/*
File Name: TestRandomGraph.cc
Author: Daniel Mallia
Date Begun: 4/22/2019

This file contains the routine for creating a "random" graph of user specified
number of vertices, where edges are edges are added until all vertices are
connected, and outputing characteristics about the graph. These outputs should
indicate that a graph does not need to be dense to achieve full connectivity.

*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "Graph.h"
#include "disjoint_sets.h"
using namespace std;

int main(int argc, char**argv) {
	if(argc != 2) {
		cout << "Usage: " << argv[0] << " <maximum_number_of_nodes>"
			  << endl << endl;
		return 0;
	}
	
	const int maxNumberofNodes(stoi(argv[1], nullptr));
	
	// Create Graph, connections map (implemented via disjoint sets class),
	// and possible unions (before only one set remains) count.
	Graph testGraph(maxNumberofNodes);
	DisjSets connectionMap(maxNumberofNodes);
	int numberOfUnionsPossible = maxNumberofNodes - 1;
	
	// Seed random number generator
	srand(time(0));
	
	// While more than one set remains...
	while(numberOfUnionsPossible > 0) {
		
		// Randomly select two vertices
		const int originId = (rand() % maxNumberofNodes) + 1;
		const int targetId = (rand() % maxNumberofNodes) + 1;
		
		// Skip if selections are equal
		if(originId == targetId) {
			continue;
		}
		
		// Add edge between vertices
		testGraph.addEdge(originId, targetId, 1.0);
		testGraph.addEdge(targetId, originId, 1.0);
		
		// Union sets in connectionMap if not already in the same set; decrement
		// number of possible unions 
		int root1 = connectionMap.find(originId - 1);
		int root2 = connectionMap.find(targetId - 1);
		
		if(root1 != root2) {
			connectionMap.unionSets(root1, root2);
			numberOfUnionsPossible--;
		}
	}
	
	// Output Graph degree information
	testGraph.outputDegreeInformation();
	
	
	return 0;
	
}
