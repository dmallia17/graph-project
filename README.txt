File Name:	README.txt
Author:		Daniel Mallia
Date Begun: 	4/24/2019

I. Assignment Completion:
I completed all parts of Homework 4.

II. Bugs:
Gradual testing of my code throughout development has appeared to remove any
issues. No bugs are known at this time.

III. Run Instructions:
Programs can be compiled individually by typing make <Program Name>, for 
example:

make CreateGraphAndTest

All programs can be compiled by typing:

make clean
make all

To delete all .o files and executables, type:

make clean

The run commands, with their expected arguments, are as follows:

./CreateGraphAndTest <graphtxtfilename> <querytxtfilename>

./FindPaths <graphtxtfilename> <#ofStartingVertex>

./TestRandomGraph <maximum_number_of_nodes>

IV. Input and Output Files:
- AdjacencyQueries1.txt and AdjacencyQueries2.txt : Both are input files 
  containing queries (in the form of two vertex identities) for the existance
  of edges (adjacency) in a directed graph. 
- Graph1.txt, Graph2.txt and Graph3.txt : All three are input files containing
  a simple numerical description of a graph in the form of the number of
  vertices followed by a list of edges with their respective weights. These
  files are used for creating graphs in the CreateGraphAndTest and FindPaths
  programs. (Graphs 2 and 3 are visualized in corresponding .png files.)


