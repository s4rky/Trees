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
    BinarySearchTree() : root(nullptr) {};
    
    /**
     @brief Builds the BST from a vectoral input.
     @details Uses insert() method to handle all logic.
     */
    BinarySearchTree(const std::vector<T>& nodes);
    
    /**
     @brief Public API to insert into BST
     */
    void insertIntoBST(const T& val);
    
    /**
     @brief Public API to delete from BST
     */
    void deleteFromBST(const T& val);
    
    /**
     @brief Public API to pretty print the BST
     */
    inline std::string prettyPrintBST();
    
    
private:
    
    void insert(std::unique_ptr<TreeNode<T>>& root, const T& val);
    
    void remove(std::unique_ptr<TreeNode<T>>& root, const T& val);
    
    std::unique_ptr<TreeNode<T>> root;
};


