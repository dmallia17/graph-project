## Author: Daniel Mallia
## Date: 7/6/2019

This is a belated upload of a software class project, written in C++, consisting of work on directed and undirected graphs. 
The project featured three major parts: 

1) Reading in directed graph specifications from a text file, representing that graph with an adjacency list-based class, and 
answering adjacency queries provided in another text file.
2) Implementing Dijkstra's algorithm using a priority queue (heap implementation) for the purpose of outputting the shortest
paths from a given vertex to all other vertices, with the associated path costs.
3) Simulating random undirected graph creation where edges are added until full graph connectivity is achieved (this is tracked
using a disjoint sets class) and then graph properties (edges and degrees) are output to illustrate that full connectivity may 
not require anywhere close to the maximum number of edges possible.

Note: This project employs some code, used with the permission of the professor, from the course textbook; instances of this 
should be clear from the head comments in the source files. 
