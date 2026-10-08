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
    BinarySearchTree(const std::vector<std::optional<T>>& nodes);
    
    /**
     @brief Public API to insert into BST
     */
    TreeNode<T>* insertIntoBST(TreeNode<T>* root, T val);
    
    /**
     @brief Public API to delete from BST
     */
    TreeNode<T>* deleteFromBST(TreeNode<T>* root, T val);
    
    
private:
    
    TreeNode<T>* insert(TreeNode<T>* root, T val);
    
    TreeNode<T>* remove(TreeNode<T>* root, T val);
    
    
    std::unique_ptr<TreeNode<T>> root;
};


