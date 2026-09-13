//
//  BinaryTree.h
//  Trees
//  Header Declaration of Binary Tree Class
//  Created by Aaron Sarkar on 2026-09-05.
//
#pragma once
#include "TreeNode.h"
#include <vector>
#include <utility>
#include <optional>
#include <set>
#include <string>

template <typename T>
class BinaryTree
{
public:
    
    /**
     @brief Default Constructor.
     */
    BinaryTree() : root(nullptr) {}
    
    /**
     @brief Constructor that builds a Binary Tree using a vector<T> input.
     Vector must also contain LNull and RNull specifications
     @param nodes Vector of nodes that is parsed to create the Binary Tree.
     */
    BinaryTree(const std::vector<std::optional<T>>& nodes);
    
    /**
     @brief Returns reference to the root of the Binary Tree.
     */
    const TreeNode<T>* getRoot() const;
    
    /**
     @brief Searches for a value in a Binary Tree. If found, returns pointer to the value. If not found, return nullptr.
     @param val The value that is being searched for.
     */
    std::pair<bool, TreeNode<T>*> search(TreeNode<T>* root, const T& val) const;
    
    /**
     @brief Uses search() and returns the pointer to a specific value being searched for in the Binary Tree.
     */
    TreeNode<T>* getNode(const T& val) const;
    
    /**
     @brief Public API to invert the Binary Tree.
     */
    void invertBinaryTree();
    
    /**
     @brief Insert value into the Binary Tree. The goal is to create a perfect and complete Binary Tree, hence why the insertion is done through a BFS.
     */
    void insertNode(const T& val);
    
    /**
     @brief Remove node from the Binary Tree.
     */
    void remove(const T& val);
    
    /**
     @brief Clear the Binary Tree. Preserves the root, but deletes everything else.
     */
    void clearTree();
    
    /**
     @brief Print a level order string representation of the Binary Tree.
     */
    void printTree() const;
    
    /**
     @brief Return size of the Binary Tree.
     */
    const int getSize() const;
    
    /**
     @brief Return number of leaves in the Binary Tree.
     */
    const int getNumLeaves() const;
    
    
    /**
     @brief Return true if Binary Tree is empty.
     */
    const bool isEmpty() const;
    
    
private:
    /**
     @brief Helper that converts Binary Tree into a Level-Ordered-String (BFS).
     */
    std::string treeToString(const std::vector<T>& levelOrderVector) const;
    
    /**
     @brief Returns true if node is present in the Binary Tree.
     */
    bool inTree(const TreeNode<T>* root) const;
    
    /**
     @brief Inverts the Binary Tree. If called an even number of times, the original tree structure will be preserved.
     */
    TreeNode<T>* invertTree(TreeNode<T>* root);
    
    /**
     @brief Helper to clear the Binary Tree.
     */
    void deleteAllExceptRoot(TreeNode<T>* root);

    
    // Member Variables
    std::unique_ptr<TreeNode<T>> root;
    
    /**
     @Todo DELETE REDUNDANT MEMBER VARS!!!
     */
    std::vector<T> levelOrderVector;
    std::set<const TreeNode<T>*> nodeSet;
    int maxDiam;
    T maxPathSum;
};
