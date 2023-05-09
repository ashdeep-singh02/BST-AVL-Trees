/*
Ashdeep Singh 
CSCI 335 
Assignment 2
Date: 03/18/2022
File Name: query_tree.cc
Purpose: Create AVL/BST tree using avl_tree.h/bst_tree.h class. Fill the object with data passed through input files. 
Locate nodes in tree which contain string passed in by user. Output results.
*/

#include "avl_tree.h"
#include "bst_tree.h"
#include "sequence_map.h"

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

namespace {


// @db_filename: an input filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.

/*
@pre: a_tree is an empty tree object
@post: tree object passed is filled with nodes containing data passed through db_filename; output the results of find calls made using user entered data
@param: db_filename- file containing recognition sequence and enzyme acronyms in pairs; a_tree- BST or AVL Tree (empty) object
*/
template <typename TreeType>
void QueryTree(const std::string &db_filename, TreeType &a_tree) {
	// Code for running Part2(a)
	// Parse input file @db_filename and feel tree @a_tree
	// Then prompt the user for exactly three strings (do a loop) and
	// provide the results of find() as described in the assignment.
	std::ifstream input;
	input.open(db_filename);
	if(!input.is_open()){
		return;
	}

	while(input){
		std::string enzyme; std::string sequence;
		input >> enzyme; input >> sequence;
		if(!input){
			break;
		}
		SequenceMap newSeqMap(sequence, enzyme); //create new sequenceMap object using data parsed
		a_tree.insert(newSeqMap); //insert new object into the tree
	}

	for(int i = 0; i < 3; i++){
		// std::cout << "Enter a recognition sequence: ";
		std::string string_to_find;
		std::cin >> string_to_find; //ask user for recognition string to search tree for
		// std::cout << endl; 
		std::cout << a_tree.find(string_to_find) << std::endl; //look for node and out put enzyme acronyms associated with it
	}
	

}

}  // namespace

int main(int argc, char **argv) {
	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <databasefilename> <tree-type>" << endl;
		return 0;
	}
	const std::string db_filename(argv[1]);
	const std::string param_tree(argv[2]);
	cout << "Input filename is " << db_filename << endl;
	cout << "Type of tree is " << param_tree << endl;
	if (param_tree == "BST") {
		BinarySearchTree<SequenceMap> a_tree;
		QueryTree(db_filename, a_tree);
		
	} else if (param_tree == "AVL") {
		AvlTree<SequenceMap> a_tree;
		QueryTree(db_filename, a_tree);
	} else {
		cout << "Uknown tree type " << param_tree << " (User should provide BST, or AVL)" << endl;
	}
	return 0;
}
