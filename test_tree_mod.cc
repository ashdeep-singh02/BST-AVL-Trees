/*
Ashdeep Singh 
CSCI 335 
Assignment 2
Date: 03/18/2022
File Name: test_tree_mod.cc
Purpose: Create Modified AVL tree using avl_tree_mod.h class. Fill the object with data passed through input files. 
Compute and output calculations.
*/

// #include "avl_tree.h"
#include "avl_tree_mod.h"
#include "sequence_map.h"

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

namespace {

// @db_filename: an input database filename.
// @seq_filename: an input sequences filename.
// @a_tree: an input tree of the type TreeType. It is assumed to be
//  empty.

/*
@pre: a_tree is an empty tree object
@post: tree object passed is filled with nodes containing data passed through db_filename; tree is manipulated; results of find() are outputted; output various calculations
@param: db_filename- file containing recognition sequence and enzyme acronyms in pairs; seq_filename- file containing list of sequences; a_tree- BST or AVL Tree (empty) object
*/
template <typename TreeType> 
void TestTree(const string &db_filename, const string &seq_filename, TreeType &a_tree) {
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

	int num_nodes = a_tree.nodeCounter();
	std::cout << "2: " << num_nodes << std::endl; //print number of nodes in tree

	int depth_sum = a_tree.depthSum(); 
	float avgerage_depth = (float)depth_sum/(float)num_nodes;
	std::cout << "3a: " << avgerage_depth << std::endl; //print the average depth of the tree
	std::cout << "3b: " << avgerage_depth/log2(num_nodes) << std::endl; //print the avg depth/log2(number of nodes)
	std::ifstream input2;
	input2.open(seq_filename);
	if(!input2.is_open()){
		return;
	}	
	int counter = 0; 
	while(input2){ 
		std::string find_sequence;
		input2 >> find_sequence; 
		if(!input2){ 
			break;
		}
		a_tree.find(find_sequence); //search the tree for nodes containing strings passed through seq_filename
		counter++;
	}
	std::cout << "4a: " << a_tree.getSuccessCounter() << std::endl; //Prints the total number of successful queries (number of strings found)
	std::cout << "4b: " << (float)a_tree.getFindCounter()/(float)counter << std::endl;  //Prints the average number of recursion calls

	std::ifstream input3;
	input3.open(seq_filename);
	if(!input3.is_open()){
		return;
	}	
	int rem_counter = 0; 
	while(input3){
		std::string seqences_remove;
		std::string skip;
		input3 >> skip;
		input3 >> skip;
		input3 >> seqences_remove;
		if(!input3){
			break;
		} 
		rem_counter++;
		a_tree.remove(seqences_remove); //remove every third element that appears in seq_filename
	} 
	std::cout << "5a: " << a_tree.getSuccessRemove() << std::endl; //Prints the total number successful removes
	std::cout << "5b: " << (float)a_tree.getRemoveCalls()/(float)rem_counter << std::endl; //Prints the average number of recursion calls

	num_nodes = a_tree.nodeCounter();  //re-calculate with updated tree
	std::cout << "6a: " << num_nodes << std::endl;
	depth_sum = a_tree.depthSum();
	avgerage_depth = (float)depth_sum/(float)num_nodes;
	std::cout << "6b: " << avgerage_depth << std::endl;
	std::cout << "6c: " << avgerage_depth/log2(num_nodes) << std::endl;
}

}  // namespace 

int main(int argc, char **argv) {
	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <databasefilename> <queryfilename>" << endl;
		return 0;
	}
	const string db_filename(argv[1]);
	const string seq_filename(argv[2]);
	cout << "Input file is " << db_filename << ", and sequences file is " << seq_filename << endl;
	// AvlTree<SequenceMap> a_tree;
	AvlTree<SequenceMap> a_tree;
	TestTree(db_filename, seq_filename, a_tree);

	return 0; 
}
