//
//  BinaryTreeOnlyChildDemo.cpp
//  SE2
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
    BinaryTree<int> tree, tree1, tree2;

    // Insert some nodes into the tree.
        cout<<endl<<"FIRST TREE"<<endl<< "Inserting nodes.\n";
        tree.insertNode(5);
        tree.insertNode(8);
        tree.insertNode(3);
        tree.insertNode(12);
        tree.insertNode(9);
        tree.insertNode(2);
        tree.insertNode(1);
        tree.insertNode(0);
    //   Display tree
        tree.displayPostOrder();
    //   Display onlyChild number
        cout<<"The number of nodes with a single child is :"<<tree.onlyChild()<<endl;
    //  output: 5

    // Insert some nodes into the tree.
        cout<<endl<<"SECOND TREE"<<endl<< "Inserting nodes.\n";
        tree1.insertNode(8);
        tree1.insertNode(9);
        tree1.insertNode(1);
        tree1.insertNode(0);
        tree1.insertNode(7);
        tree1.insertNode(2);
        tree1.insertNode(3);
        tree1.insertNode(4);
    //   Display tree
        tree1.displayPostOrder();
    //   Display onlyChild number
        cout<<"The number of nodes with a single child is :"<<tree1.onlyChild()<<endl;
    //  output: 3

    // Insert some nodes into the tree.
        cout<<endl<<"THIRD TREE"<<endl<< "Inserting nodes.\n";
        tree2.insertNode(4);
        tree2.insertNode(6);
        tree2.insertNode(8);
        tree2.insertNode(10);
        tree2.insertNode(12);
        tree2.insertNode(30);
        tree2.insertNode(35);
        tree2.insertNode(60);
    //   Display tree
        tree2.displayPostOrder();
    //   Display onlyChild number
        cout<<"The number of nodes with a single child is :"<<tree2.onlyChild()<<endl;
    //  output: 7
    return 0;
}
