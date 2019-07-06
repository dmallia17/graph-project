/*
File Name: disjoint_sets.h
Author: Daniel Mallia (Header comment; formatting; carried out merging of the
		  disjoint_sets .h and .cc files; added error checking). The majority of
		  the code below was provided by Professor Stamos, and sourced from
		  Data Structures and Algorithm Analysis in C++, 4th edition, by Mark
		  Allen Weiss.
Date Begun: 4/22/2019

This header file contains the interface and implementation (for ease of
compilation) of the DisjSets class.
*/

#ifndef DISJ_SETS_H
#define DISJ_SETS_H

// DisjSets class
//
// CONSTRUCTION: with int representing initial number of sets
//
// ******************PUBLIC OPERATIONS*********************
// void union( root1, root2 ) --> Merge two sets
// int find( x )              --> Return set containing x
//										(const and non-const versions
//										 available)
// ******************ERRORS********************************
// Throws ArrayIndexOutOfBoundsException as warranted.

#include <vector>
#include "dsexceptions.h"
using namespace std;

/**
 * Disjoint set class.
 * Use union by rank and path compression.
 * Elements in the set are numbered starting at 0.
 */
class DisjSets {
public:

	/**
 	 * Construct the disjoint sets object.
 	 * numElements is the initial number of disjoint sets.
	 */
	explicit DisjSets(int numElements) : s(numElements, -1) { }

	/**
	 * Perform a find.
	 * Throw out of bounds if x is an invalid set identity.
	 * Otherwise, return the set containing x.
	 */
	int find(int x) const {
		// Check for valid set selection
		if(!isValid(x)) {
			throw ArrayIndexOutOfBoundsException{};
		}
		
		if(s[x] < 0 ) {
			return x;
		}
		else {
			return find(s[x]);
		}
	}
	
	/**
	 * Perform a find with path compression.
	 * Throw out of bounds if x is an invalid set identity.
	 * Otherwise, return the set containing x.
	 */
	int find(int x) {
		// Check for valid set selection
		if(!isValid(x)) {
			throw ArrayIndexOutOfBoundsException{};
		}
		
		if(s[x] < 0 ) {
			return x;
		}
		else {
			return s[x] = find(s[x]);
		}
	}
	
	/**
	 * Union two disjoint sets.
	 * Throw out of bounds if root1 or root2 is an invalid set identity.
	 * For simplicity, we assume root1 and root2 are distinct
	 * and represent set names.
	 * root1 is the root of set 1.
	 * root2 is the root of set 2.
	 */
	void unionSets(int root1, int root2) {
		// Check for valid set selections
		if(!isValid(root1) || !isValid(root2)) {
			throw ArrayIndexOutOfBoundsException{};
		}
		
		// Cannot union the same set with itself
		if(root1 == root2) {
			return;
		}
		
		if(s[root2] < s[root1]) {  // root2 is deeper
			s[root1] = root2;        // Make root2 new root
		}
		else {
			if(s[root1] == s[root2]) {
				--s[root1];          // Update height if same
			}
			s[root2] = root1;        // Make root1 new root
		}
	}

private:
	vector<int> s;
	
	// Check for valid set selection.
	// @identity	Identity (integer) of a set.
	// @return		True if identity is within range of possible set ids; false
	//					otherwise.
	bool isValid(const int identity) const {
		if(identity < 0 || identity >= static_cast<int>(s.size())) {
			return false;
		}
		
		return true;
	}
};

#endif /* DisjSets_h */
