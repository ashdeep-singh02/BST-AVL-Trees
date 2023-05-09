# BST & AVL Tree Implementation
Ashdeep Singh

CSCI 335 (Hunter College)

The goal of this project was to become familiarized with BST and AVL tree operations, along with comparing the performance between the two tree structures. Our main objective of this program was to construct BST/AVL trees using data passed in via txt files. While we were provided with the basic implementation of the BST/AVL data structures, we had to implement more member functions inorder to complete out task. 

Added Tree Member Functions:
  * find- Return the enzyme acronym associated with the recognition sequence passed in
  * depthSum- calculate and return the depth sum of the tree (internal path length)
  * nodeCounter- return the total number of nodes in the tree


 Modified Tree Member Functions:
  * remove- have counters for number of recursive calls and number of successful calls
  * insert- account for merge case (if item being inserted already exists, merge with pre-existing node); have counters to count number of queries to it
  * doubleWithRightChild- (modified only in avl_tree_mod.h) use double roation without call to single rotation
  * doubleWithLeftChild- (modified only in avl_tree_mod.h) use double roation without call to single rotation


Along with modifying the tree implementation, we had to implement the Sequence Map Objects themselves contained in sequence_map.h. 

Sequence Map member functions:
 * Big 5 Constructors and Destructor- Create/Delete nodes
 * 2 parameter SequenceMap constructor- create new node given the recognition sequence and enzyme acronyms
 * operator< - less than comparator
 * operator> - greater than comparator
 * operator>> - input operator
 * operator<< - output operator
 * Merge- Merge one Sequence Map Object with another
 * getRecStr- return the recognition sequence
 * getEnzyme - return the enzyme acronyms
 * getEnzymeVector - return vector of enzyme acronyms


Once our node and trees were fully implemented we could proceed with the main task at hand. Parsing a file and constructing trees with the data. 

In query_tree.cc, we had the simple task of parsing a file containing the enzyme acronyms and recognition sequence. Using the two parameter constructor, a Sequence Map Object was created and inserted into the tree structure. From here, we called the find function which accepted a recognition sequence as a parameter, and returned the corresponding enzyme acronyms.

In test_tree.cc, we had a similar task. Once the file data was parsed, and the tree was constructed, we were to:
 1) Print the number of nodes in the tree
 2) Computes the average depth of the search tree
 3) Call the find() function on all the data items in another file passed in (sequences.txt)
 4) Removes every third sequence in sequences.txt from the tree

Finally, in the test_tree_mod file, we implemented a avl_tree_mod.h tree and computed the same task as with test_tree.cc. avl_tree_mod.h only differed in its implementation of the double rotations (described above).  

Bugs Encountered:
 * test_tree_mod.c file wouldn't compile on gradescope but compiled locally. The solution as it turned out was the I had forgotten to include cmath. Due to this, log2N was unable to be executed. Through this bug I learned that programs run differently on VSC and on the actual linux machine.   
 * Double Tree rotations weren't working properly in avl_tree_mod.h. The error in this was that I was incorrectly updating the heights of the nodes. 
 * Casting to float error- Whenever I tried to divide two integers, and store them into a float variable, I wouln't get any decimal values. As it turns out, the integers had to be casted into a float BEFORE they are divided and stored. 
 * Getline would read in white spaces- My first attempt to read in the data file was to use getline. Through this method however, it was difficult to separate the meaningful data from the useless whitespaces. To solve this issue, I resorted to using the extraction operators and fstreams, which ignore white spaces. 

# Input Files:
 * input_part2a.txt - test inputs for part 2(a)
 * sequences.txt - collection of recognition sequences
 * rebase210.txt - pairs of recognition sequences and enzyme acronyms

# Compiling and Running 
To compile on terminal, type:
```bash
make
```

You can compile one program individually by just typing `make <Program Name>`, for example:
```bash
make query_tree
```

To delete executables and object files, type:
```bash
make clean
```

To run Query Tree, type:
```bash
./query_trees rebase210.txt BST < input_part2a.txt
./query_trees rebase210.txt AVL < input_part2a.txt
```

To run Test Tree, type:
```bash
./test_tree rebase210.txt sequences.txt AVL
./test_tree rebase210.txt sequences.txt BST
```

To run Test Tree Mod, type:
```bash
./test_tree_mod rebase210.txt sequences.txt
```
