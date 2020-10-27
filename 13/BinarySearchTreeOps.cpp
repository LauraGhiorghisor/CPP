//
//  BinarySearchTreeOps.cpp
//  Assessment2
//
//  Created by Laura Ghiorghisor on 23/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "BinaryTree.hpp"
using namespace std;

int main()
{

    BinaryTree<int> T1, T2, T3;

// Insert some nodes into the tree T1 - point a)
    cout<<endl<<"T1 TREE"<<endl<< "Inserting nodes.\n";
    T1.insertNode(5);
    T1.insertNode(8);
    T1.insertNode(3);
    T1.insertNode(12);
    T1.insertNode(9);
    T1.insertNode(2);
    T1.insertNode(1);
    T1.insertNode(0);
// Display T1
    T1.displayInOrder();
    cout<<endl;

//  b) Do a post order traversal of T1 and while doing the post order traversal, insert the nodes into a second binary search tree T2
    cout<<endl<<"Calling b)"<<endl;
    T1.publicDisplayPostOrderAndInsert(T2);
    cout<<endl<<"T2 is now :"<<endl;
    T2.displayInOrder(); cout<<endl;


// c) Do a preorder traversal of T2 and while doing the preorder traversal, insert the node into a third binary search tree T3
     cout<<endl<<"Calling c)"<<endl;
    T2.publicDisplayPreOrderAndInsert(T3);
    cout<<endl<<"T3 is now :"<<endl;
    T3.displayInOrder(); // In order traversal of T3. d)



// e) Output the heights and the number of leafs in each of the three binary search trees
//  HEIGHT
    cout<<"HEIGHTS : "<<endl;
    cout<<"The height of T1 is : "<<T1.height()<<endl;
    cout<<"The height of T2 is : "<<T2.height()<<endl;
    cout<<"The height of T3 is : "<<T3.height()<<endl;

//  NUMBER OF LEAVES
    cout<<"NUMBER OF LEAVES"<<endl;
    cout<<"The number of leaves of T1 is"<<T1.countLeaves()<<endl;
    cout<<"The number of leaves of T2 is"<<T2.countLeaves()<<endl;
    cout<<"The number of leaves of T3 is"<<T3.countLeaves()<<endl;

    return 0;
}
