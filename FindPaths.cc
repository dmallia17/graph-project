/*
File Name: FindPaths.cc
Author: Daniel Mallia
Date Begun: 4/18/2019

This file contains the routine for testing use of Dijkstra's Algorithm on the
Graph class to output the shortest paths from a given starting vertex to all
vertices in the graph.

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Graph.h"
using namespace std;

// Utility function for opening input/query files.
// @filename	Valid filename of a .txt file.
// @return		Returns an input file stream if properly initialized; else
//					exits with error code 1.
ifstream openFile(const string filename) {
	ifstream input;
	
	// Open input file
	input.open(filename);
	
	// Check for failure to open input file
	if(input.fail()) {
		cout << "Cannot read from " << filename;
		exit(1);
	}
	
	return input;
}

// Function for generating a graph based on .txt input file specifications.
// @graph_filename	Valid filename of a .txt file containing graph
//							specifications: size, followed by a list of directed edges.
// @return				Returns a Graph initialized as specified in the .txt file.
// Pre-Condition: 	Input contains properly formatted graph information. This
//							pre-condition is NOT checked. 
Graph createGraph(const string graph_filename) {
	// Open graph input file
	ifstream graphInput = openFile(graph_filename);
	
	int size(0), originVertex(0), targetVertex(0);
	float edgeWeight(0.0);
	
	string line;
	stringstream sLine;
	
	// Read in size and initialize Graph
	getline(graphInput, line);
	sLine.str(line);
	sLine >> size;
	Graph newGraph(size);
	
	// Read in directed edges and construct Graph
	while(getline(graphInput, line)) {
		sLine.clear();
		sLine.str(line);
		
		sLine >> originVertex;
		
		while(sLine >> targetVertex) {
			sLine >> edgeWeight;
			
			newGraph.addEdge(originVertex, targetVertex, edgeWeight);
		}
	}
	
	//Close file
	graphInput.close();
	
	return newGraph;
}

int main(int argc, char**argv) {
	if(argc != 3) {
		cout << "Usage: " << argv[0] << " <graphtxtfilename> <#ofStartingVertex>"
			  << endl << endl;
		
		return 0;
	}
	
	const string graph_filename(argv[1]);
	const int startVertex(stoi(argv[2], nullptr));
	
	// Create Graph
	Graph testGraph = createGraph(graph_filename);
	
	// Run Dijkstra's Algorithm on testGraph
	testGraph.dijkstra(startVertex);

	return 0;
}
