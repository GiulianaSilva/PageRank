#include <iostream>
#include <map>
#include <iomanip>
#include <vector>

#include "AdjacencyList.h"

using namespace std;

int main() {

    AdjacencyList Graph;

    int no_of_lines, power_iterations;
    string from, to;
    cin >> no_of_lines;
    cin >> power_iterations;
    for (int i = 0; i < no_of_lines; i++) {
        cin >> from;
        cin >> to;
        Graph.insertEdge(from, to);
    }

    Graph.PageRank(power_iterations);
    return 0;

}


