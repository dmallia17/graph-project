################################################
##
## Makefile
## LINUX Compilation
##
################################################

# FLAGS
C++FLAG = -g -std=c++11 -Wall

# Math Library
MATH_LIBS = -lm
EXEC_DIR = .

# Rule for .cpp files
# .SUFFIXES : .cc.o

.cc.o:
	g++ $(C++FLAG) $(INCLUDES) -c $< -o $@

INCLUDES = -I.

LIBS_ALL = -L/usr/lib -L/usr/local/lib $(MATH_LIBS)

# ZEROTH PROGRAM
ALL_OBJ0 = CreateGraphAndTest.o
PROGRAM_0 = CreateGraphAndTest
$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)

# FIRST PROGRAM
ALL_OBJ1 = FindPaths.o
PROGRAM_1 = FindPaths
$(PROGRAM_1): $(ALL_OBJ1)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ1) $(INCLUDES) $(LIBS_ALL)

# SECOND PROGRAM
ALL_OBJ2 = TestRandomGraph.o
PROGRAM_2 = TestRandomGraph
$(PROGRAM_2): $(ALL_OBJ2)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ2) $(INCLUDES) $(LIBS_ALL)

# Compiling all

all:

	make $(PROGRAM_0)
	make $(PROGRAM_1)
	make $(PROGRAM_2)

run1Graph:
		./$(PROGRAM_0) Graph1.txt AdjacencyQueries.txt

run2Graph:
		./$(PROGRAM_1) Graph2.txt <startVertex>

run3Graph:
		./$(PROGRAM_2) <maxNumberofVertices>

# Clean obj files

clean:
	(rm -f *.o; rm -f $(PROGRAM_0); rm -f $(PROGRAM_1); rm -f $(PROGRAM_2))


