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
     @brief Traversal types for Binary Tree.
     */
    enum class Traversal
    {
        Inorder,
        Preorder,
        Postorder,
        Levelorder
    };
    
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
    std::pair<bool, const TreeNode<T>*> search(const TreeNode<T>* root, const T& val) const;
    
    /**
     @brief Searches for the lowest common ancestor of any 2 nodes in the Binary Tree.
     */
    const TreeNode<T>* lowestCommonAncestor(const TreeNode<T>* node1, const TreeNode<T>* node2) const;
    
    /**
     @brief Uses search() and returns the pointer to a specific value being searched for in the Binary Tree.
     */
    const TreeNode<T>* getNode(const T& val) const;
    
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
    const int getMaxDiameter();
    
    /**
     @brief Return maximum path sum (max path sum between any 2 nodes [inclusive]) of the Binary Tree.
     */
    const T getMaxPathSum();
    
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
     @brief Public API that traverses the Binary Tree based on input string.
     @param traversalType Traversal  type input where user can query a traversal type.
     @note The following are the traversal types.
     1. Inorder Traversal (Traversal::Inorder)
     2. Postorder Traversal (Traversal::Postorder)
     3. Preorder Traversal (Traversal::Preorder)
     4. Level-Order Traversal (Traversal::LevelOrder)
     */
    std::string traverse(const Traversal traversalType);
    
    /**
     @brief Returns a vector of vectors that return all root-to-leaf paths that add up to a target sum.
     @param target The target sum.
     */
    std::vector<std::vector<T>> pathsThatSumTo(const T& target);
    
    /**
     @brief Returns a vectoral representation of a Breadth-First-Search (BFS).
     */
    std::vector<std::vector<T>> levelOrderTraversal();
    
    
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
    bool traverseForPath(const TreeNode<T>* root, const TreeNode<T>* target, std::vector<const TreeNode<T>*>& path) const;
    
    /**
     @brief Helper to calculate maximum diameter of the Binary Tree.
     */
    int calculateMaxDiameter(const TreeNode<T>* root);
    
    /**
     @brief Helper to calculate maximum path sum of the Binary Tree.
     */
    T calculateMaxPathSum(const TreeNode<T>* root);
    
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
    
    /**
     @brief Helper to construct inorder traversal vector of Binary Tree.
     */
    void inorder(const TreeNode<T>* root, std::vector<const TreeNode<T>*>& inorderVec);
    
    /**
     @brief Helper to construct preorder traversal vector of Binary Tree.
     */
    void preorder(const TreeNode<T>* root, std::vector<const TreeNode<T>*>& preorderVec);
    
    /**
     @brief Helper to construct postorder traversal vector of Binary Tree.
     */
    void postorder(const TreeNode<T>* root, std::vector<const TreeNode<T>*>& postorderVec);
    
    /**
     @brief Inverts the Binary Tree. If called an even number of times, the original tree structure will be preserved.
     */
    TreeNode<T>* invertTree(TreeNode<T>* root);
    
    /**
     @todo Add this to a utils class or something
     @brief Helper to turn a vector into a string.
     */
    std::string vecToString(const std::vector<T> vec);
    
    /**
     @brief Helper that constructs a vector with numeric values that sum up to a target in the Binary Tree. Used by public pathsThatSumTo() API.
     */
    void constructPathForTargetSum(const TreeNode<T>* root, const T& targetSum, std::vector<T>& path, std::vector<std::vector<T>>& paths, T currSum);
    
    // Member Variables
    std::unique_ptr<TreeNode<T>> root;
    std::vector<T> levelOrderVector;
    std::vector<const TreeNode<T>*> inorderVec;
    std::vector<const TreeNode<T>*> preorderVec;
    std::vector<const TreeNode<T>*> postorderVec;
    std::set<const TreeNode<T>*> nodeSet;
    int height;
    int maxDiam;
    T maxPathSum;
};


