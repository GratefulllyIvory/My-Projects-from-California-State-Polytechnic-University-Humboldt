/*---
    CS 211 Spring 2021 - Programming Assignment 02
    Binary Search Tree methods

    David C. Tuttle
    Last Modified: 26 Mar 2021
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "BST.h"

using namespace std;

int main() {
    cout << boolalpha;

    // Create some test trees to perform tests with
    
    int t1_nodes[7] = {20, 10, 30, 5, 15, 25, 35};
    int t2_nodes[20] = {500, 250, 750, 150, 350,
                        650, 850, 125, 175, 325,
                        375, 625, 675, 825, 875,
                        110, 330, 670, 870, 873};
    int t3_nodes[6] = {6, 5, 4, 3, 2, 1};
    // t4 will be a tree with one node with value 1000
    // t5 will be an empty tree with no nodes

    // Create and populate the trees
    BST *tree_1 = new BST();
    for (int i=0; i<7; i++)
        tree_1->insert(t1_nodes[i]);
    
    BST *tree_2 = new BST();
    for (int i=0; i<20; i++)
        tree_2->insert(t2_nodes[i]);
    
    BST *tree_3 = new BST();
    for (int i=0; i<6; i++)
        tree_3->insert(t3_nodes[i]);
    
    BST *tree_4 = new BST();
    tree_4->insert(1000);
    
    BST *tree_5 = new BST();

    //*******************************************
    // Demontration of exampleTraversal on tree_1
    //*******************************************
    
    // tree_1 start as:
    //               +----20----+
    //           +--10--+    +--30--+
    //           5     15    25    35

    cout << "*** Example traversal of tree_1 (using recursion) *** \n";
    cout << "(A * indicates a leaf node) \n";
    tree_1->exampleTraversal();
    cout << endl << endl;

    cout << "*** READY FOR TESTING! *** \n";

    // UNCOMMENT THE LINES BELOW TO RUN TESTS USING ALL THE TREES
    
//    cout << endl << "*** TREE 1 TEST ***";
//    cout << endl << "Preorder traversal" << endl << "    ";
//    tree_1->preorderTraversal();
//    cout << endl << "Inorder traversal" << endl << "    ";
//    tree_1->inorderTraversal();
//    cout << endl << "Postorder traversal" << endl << "    ";
//    tree_1->postorderTraversal();
//    cout << endl << "Node count (should be 7): "
//         << tree_1->countNodes() << endl;
//    cout << "Leaf count (should be 4): "
//         << tree_1->countLeaves() << endl;
//    cout << "Right child count (should be 3): "
//         << tree_1->countRChildren() << endl;
//    cout << "Tree height (should be 2): "
//         << tree_1->treeHeight() << endl;
//    cout << "Deleting nodes!" << endl << endl;
//    tree_1->deleteAllNodes();
//    cout << endl << "Node count (should be 0): "
//         << tree_1->countNodes() << endl;

//    delete tree_1;

//    cout << endl << "*** TREE 2 TEST ***";
//    cout << endl << "Preorder traversal" << endl << "    ";
//    tree_2->preorderTraversal();
//    cout << endl << "Inorder traversal" << endl << "    ";
//    tree_2->inorderTraversal();
//    cout << endl << "Postorder traversal" << endl << "    ";
//    tree_2->postorderTraversal();
//    cout << endl << "Node count (should be 20): "
//         << tree_2->countNodes() << endl;
//    cout << "Leaf count (should be 8): "
//         << tree_2->countLeaves() << endl;
//    cout << "Right child count (should be 9): "
//         << tree_2->countRChildren() << endl;
//    cout << "Tree height (should be 5): "
//         << tree_2->treeHeight() << endl;
//    cout << "Deleting nodes!" << endl << endl;
//    tree_2->deleteAllNodes();
//    cout << "Leaf count (should be 0): "
//         << tree_2->countLeaves() << endl;
//    delete tree_2;

//    cout << endl << "*** TREE 3 TEST ***";
//    cout << endl << "Preorder traversal" << endl << "    ";
//    tree_3->preorderTraversal();
//    cout << endl << "Inorder traversal" << endl << "    ";
//    tree_3->inorderTraversal();
//    cout << endl << "Postorder traversal" << endl << "    ";
//    tree_3->postorderTraversal();
//    cout << endl << "Node count (should be 6): "
//         << tree_3->countNodes() << endl;
//    cout << "Leaf count (should be 1): "
//         << tree_3->countLeaves() << endl;
//    cout << "Right child count (should be 0): "
//         << tree_3->countRChildren() << endl;
//    cout << "Tree height (should be 5): "
//         << tree_3->treeHeight() << endl;
//    cout << "Deleting nodes!" << endl << endl;
//    tree_3->deleteAllNodes();
//    cout << endl << "Node count (should be 0): "
//         << tree_3->countNodes() << endl;
//    delete tree_3;

//    cout << endl << "*** TREE 4 TEST ***";
//    cout << endl <<"Preorder traversal" << endl << "    ";
//    tree_4->preorderTraversal();
//    cout << endl << "Inorder traversal" << endl << "    ";
//    tree_4->inorderTraversal();
//    cout << endl << "Postorder traversal" << endl << "    ";
//    tree_4->postorderTraversal();
//    cout << endl << "Node count (should be 1): "
//         << tree_4->countNodes() << endl;
//    cout << "Leaf count (should be 1): "
//         << tree_4->countLeaves() << endl;
//    cout << "Right child count (should be 0): "
//         << tree_4->countRChildren() << endl;
//    cout << "Tree height (should be 0): "
//         << tree_4->treeHeight() << endl;
//    cout << "Deleting nodes!" << endl << endl;
//    tree_4->deleteAllNodes();
//    cout << endl << "Node count (should be 0): "
//         << tree_4->countNodes() << endl;
//    delete tree_4;

//    cout << endl << "*** TREE 5 TEST ***";
//    cout << endl << "Preorder traversal" << endl << "    ";
//    tree_5->preorderTraversal();
//    cout << endl << "Inorder traversal" << endl << "    ";
//    tree_5->inorderTraversal();
//    cout << endl << "Postorder traversal" << endl << "    ";
//    tree_5->postorderTraversal();
//    cout << endl << "Node count (should be 0): "
//         << tree_5->countNodes() << endl;
//    cout << "Leaf count (should be 0): "
//         << tree_5->countLeaves() << endl;
//    cout << "Right child count (should be 0): "
//         << tree_5->countRChildren() << endl;
//    cout << "Tree height (should be -1): "
//         << tree_5->treeHeight() << endl;
//    cout << "Deleting nodes!" << endl << endl;
//    tree_5->deleteAllNodes();
//    cout << endl << "Node count (should be 0): "
//         << tree_5->countNodes() << endl;
//    delete tree_5;

    return EXIT_SUCCESS;
}