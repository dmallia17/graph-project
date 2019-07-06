/*
File Name: CreateAndTestGraph.cc
Author: Daniel Mallia
Date Begun: 4/17/2019

This file contains the routine for testing creation and querying of the
Graph class, used to represent a graph as specified by a .txt file.

*/

#include <iostream>
#include <fstream>
#include "Graph.h"
#include <string>
#include <sstream>
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

// Function for querying a pre-existing directed graph.
// @query_filename 	Filename of .txt file containing edge queries (edge origin
//							and target pairs).
// @testGraph			Graph to be queried.
// Pre-Conditions:	testGraph is a properly initialized Graph and
//							query_filename is a valid .txt filename.
// Post-Conditions:	Results of all edge queries have been output.
void queryGraph(const string query_filename, Graph & testGraph) {
	// Open query file
	ifstream queryInput = openFile(query_filename);
	
	int originVertex(0), targetVertex(0);
	float edgeWeight (0.0);
	string line;
	stringstream sLine;
	
	// For each edge query, check if edge exists between the origin and "target"
	//	vertices.
	while(getline(queryInput, line)) {
		sLine.clear();
		sLine.str(line);
		
		sLine >> originVertex >> targetVertex;
		
		edgeWeight = testGraph.isConnected(originVertex, targetVertex);
		
		if(originVertex == targetVertex) {
			cout << originVertex << " " << targetVertex
				  << ": Same vertex - implicit weight of 0";
		}
		else if(edgeWeight != -1.0) {
			cout << originVertex << " " << targetVertex
				  << ": Connected, weight of edge is " << edgeWeight;
		}
		else {
			cout << originVertex << " " << targetVertex
				  << ": Not connected";
		}
		
		cout << endl;
	}
	
	cout << endl;
	
	//Close file
	queryInput.close();
}

// Main function for graph creation and test routine.
int main(int argc, char **argv) {
	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <graphtxtfilename> <querytxtfilename>"
			  << endl << endl;
		return 0;
	}
	
	const string graph_filename(argv[1]);
	const string query_filename(argv[2]);
	
	// Create Graph
	Graph testGraph = createGraph(graph_filename);
	
	// Test Graph
	queryGraph(query_filename, testGraph);

	return 0;
}
