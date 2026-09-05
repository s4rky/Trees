//
//  BinaryTree.h
//  Trees
//  Header Declaration of Binary Tree Class
//  Created by Aaron Sarkar on 2026-09-05.
//
#pragma once
#include "TreeNode.h"
#include <vector>
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
    const TreeNode<T>* search(const T& val) const;
    
    /**
     @brief Searches for the lowest common ancestor of any 2 nodes in the Binary Tree.
     */
    const TreeNode<T>* lowestCommonAncestor(const TreeNode<T>* node1, const TreeNode<T>* node2) const;
    
    /**
     @brief Inverts the Binary Tree. If called an even number of times, the original tree structure will be preserved.
     */
    TreeNode<T>* invertTree(TreeNode<T>* root);
    
    /**
     @brief Insert node into the Binary Tree.
     */
    void insertNode();
    
    /**
     @brief Remove node from the Binary Tree.
     */
    void removeNode();
    
    /**
     @brief Clear the Binary Tree.
     */
    void clearTree();
    
    /**
     @brief Clone the Binary Tree (Deep Copy).
     */
    void cloneTree();
    
    /**
     @brief Print a level order string representation of the Binary Tree.
     */
    void printTree() const;
    
    /**
     @brief Return size of the Binary Tree.
     */
    const int getSize() const;
    
    /**
     @brief Return height (maximum depth) of the Binary Tree.
     */
    int getHeight();
    
    /**
     @brief Return maximum diameter (most number of edges between any 2 nodes) of the Binary Tree.
     */
    const int getMaxDiameter() const;
    
    /**
     @brief Return maximum path sum (max path sum between any 2 nodes [inclusive]) of the Binary Tree.
     */
    const int getMaxPathSum() const;
    
    /**
     @brief Return number of leaves in the Binary Tree.
     */
    const int getNumLeaves() const;
    
    /**
     @brief Return true if Binary Tree is empty.
     */
    bool isEmpty();
    
    /**
     @brief Return true if 2 comared trees are identical.
     */
    bool isSameTree(TreeNode<T>& root);
    
    
    /**
     @brief Returns a vector of vectors that return all root-to-leaf paths that add up to a target sum.
     @param target The target sum.
     */
    std::vector<std::vector<int>> pathsThatSumTo(const int& target);
    
    /**
     @brief Returns a vectoral representation of a Breadth-First-Search (BFS).
     */
    std::vector<std::vector<T>> levelOrderTraversal();
    
    /**
     @brief Inorder traversal (L, Rt, R) of a Binary Tree.
     */
    std::vector<T> inorderTraversal();
    
    /**
     @brief Preorder traversal (Rt, L, R) of a Binary Tree.
     */
    std::vector<T> preorderTraversal();
    
    /**
     @brief Postorder traversal (L, R, Rt) of a Binary Tree.
     */
    std::vector<T> postorderTraversal();
    
private:
    /**
     @brief Helper that converts Binary Tree into a Level-Ordered-String (BFS).
     */
    std::string treeToString(const std::vector<T>& levelOrderVector) const;
    
    /**
     @brief Return height (maximum depth) of the Binary Tree.
     */
    int calculateHeight(TreeNode<T>* root) const;
    
    /**
     @brief Returns true if node is present in the Binary Tree.
     */
    bool inTree(const TreeNode<T>* root) const;
    
    /**
     @brief Helper that traverses the Binary Tree for a given target and mutates an input vector.
     */
    bool traverseForPath(const TreeNode<T>* root, const T& target, std::vector<T>& path) const;
    
    // Member Variables
    std::unique_ptr<TreeNode<T>> root;
    std::vector<T> levelOrderVector;
    std::set<const TreeNode<T>*> nodeSet;
    int height;
};


