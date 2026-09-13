//
//  BinarySearchTree.h
//  Trees
//
//  Created by Aaron Sarkar on 2026-09-11.
//

#pragma once
#include "TreeNode.h"
#include "BinaryTree.h"

template <typename T>

class BinarySearchTree
{
public:
    BinarySearchTree() : root(nullptr);
    
    /**
     @brief Does a check to see if nodes is a valid BST as vector input. If it isn't do not build the BST.
     @param nodes The input vector to construct the BST
     */
    BinarySearchTree(const std::vector<std::optional<T>>& nodes);
    
    
    
private:
    std::unique_ptr<TreeNode<T>> root;
    BinaryTree tree;
};


