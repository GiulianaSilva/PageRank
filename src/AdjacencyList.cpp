#include <iostream>
#include "AdjacencyList.h"
using namespace std;

int AdjacencyList::numVertices(){
    return inDeg.size();
}


void AdjacencyList::initialRank() {
    for(auto it = inDeg.begin(); it != inDeg.end();  it++){
        pageRankMap[it->first] = 1.0f/ numVertices();
    }
}


void AdjacencyList::insertEdge(string from, string to){
    outDeg[from] += 1;
    inDeg[to].push_back(from);

    //maps do not allow duplicate keys
    outDeg.insert({to,0});
    inDeg.insert({from,{}});
}


// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
string AdjacencyList::PageRank(int n){
    initialRank();

    for(int i = 1; i < n; i++){
        map<string, float> newRanks;
        //map to hold all old ranks until next iteration
        map<string, float> oldRanks =pageRankMap;

        for(auto it = inDeg.begin(); it != inDeg.end();  it++){
            string webpage = it->first;
            vector<string> links = it->second;
            float sum = 0.0f;

           for(int j = 0; j < links.size(); j++){
               string link = links[j];
               if(outDeg.find(link) != outDeg.end() && outDeg[link] > 0){
                   sum += (1.0f / outDeg[link]) * oldRanks[link];
               }
           }
           newRanks[webpage] = sum;
        }
        pageRankMap = newRanks;
    }
    stringstream result;

    //changes pageRankMap into vector of pairs to sort alphabetically
    vector<pair<string, float>> sortedRanks(pageRankMap.begin(), pageRankMap.end());
    sort(sortedRanks.begin(), sortedRanks.end());

    for (auto& rank : sortedRanks) {
        result << rank.first << " " << fixed << setprecision(2) << rank.second << "\n";
    }

    cout << result.str();
    return result.str();
}
