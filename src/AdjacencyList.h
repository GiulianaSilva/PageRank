#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class AdjacencyList {
    private:
    unordered_map<string, unsigned int> outDeg;
    unordered_map<string, vector<string>> inDeg;
    map<string, float> pageRankMap;


    public:
    void initialRank();
    int numVertices();
    void insertEdge(string from, string to);
    string PageRank(int n);
};
