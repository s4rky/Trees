//
//  BinaryTree.cpp
//  Trees
//  Implementation of Binary Tree Class
//  Created by Aaron Sarkar on 2026-09-05.
//


#include "BinaryTree.h"
#include <queue>
#include <sstream>
#include <iostream>


template <typename T>
BinaryTree<T>::BinaryTree(const std::vector<std::optional<T>>& nodes)
{
    if (nodes.empty() || !nodes[0].has_value())
    {
        root = nullptr;
        return;
    }
    std::queue<TreeNode<T>*> q;
    root = std::make_unique<TreeNode<T>>(nodes[0].value());
    q.push(root.get());
    levelOrderVector.push_back(root->val);
    nodeSet.insert(root.get());
    size_t p2 = 1;
    size_t p3 = 2;
    
    while (!q.empty())
    {
        const size_t size = q.size();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode<T>* node = q.front();
            q.pop();
            if (p2 < nodes.size() && nodes[p2].has_value())
            {
                node->left = std::make_unique<TreeNode<T>>(nodes[p2].value());
                q.push(node->left.get());
                levelOrderVector.push_back(node->left->val);
                nodeSet.insert(node->left.get());
            }
            if (p3 < nodes.size() && nodes[p3].has_value())
            {
                node->right = std::make_unique<TreeNode<T>>(nodes[p3].value());
                q.push(node->right.get());
                levelOrderVector.push_back(node->right->val);
                nodeSet.insert(node->right.get());
            }
            p2 += 2;
            p3 += 2;
        }
    }
}

template <typename T>
const TreeNode<T>* BinaryTree<T>::getRoot() const
{
    return root.get();
}

template <typename T>
bool BinaryTree<T>::inTree(const TreeNode<T>* root) const
{
    auto found = nodeSet.find(root) != nodeSet.end();
    return found;
}

template <typename T>
bool BinaryTree<T>::traverseForPath(const TreeNode<T>* root, const T& target, std::vector<T>& path) const
{
    if (!root)
    {
        return false;
    }
    if (root->val == target)
    {
        path.push_back(root->val);
        return true;
    }
    path.push_back(root->val);
    if (traverseForPath(root->left.get(), target, path) || traverseForPath(root->right.get(), target, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}

template <typename T>
const TreeNode<T>* BinaryTree<T>::lowestCommonAncestor(const TreeNode<T>* node1, const TreeNode<T>* node2) const
{
    if (!root || !inTree(node1) || !inTree(node2))
    {
        return nullptr;
    }
    std::vector<T> node1Vec;
    traverseForPath(root.get(), node1->val, node1Vec);
    std::vector<T> node2Vec;
    traverseForPath(root.get(), node2->val, node2Vec);
    size_t n1Ptr = 0;
    size_t n2Ptr = 0;
    size_t n1Size = node1Vec.size();
    size_t n2Size = node2Vec.size();
    
    while ((n1Ptr < n1Size - 1 && n2Ptr < n2Size - 1) && (node1Vec[n1Ptr + 1] == node2Vec[n2Ptr + 1]))
    {
        n1Ptr++;
        n2Ptr++;
    }
    
    return node1Vec[n1Ptr];
}

template <typename T>
std::string BinaryTree<T>::treeToString(const std::vector<T>& levelOrderVector) const
{
    std::string treeAsString = "";
    if (levelOrderVector.empty())
    {
        return treeAsString;
    }
    for (const auto& node: levelOrderVector)
    {
        if (!treeAsString.empty())
        {
            treeAsString += ",";
        }
        std::ostringstream oss;
        oss << node;
        treeAsString += oss.str();
    }
    return treeAsString;
}

template <typename T>
void BinaryTree<T>::printTree() const
{
    const std::string tree = treeToString(levelOrderVector);
    std::cout << tree << std::endl;
}

template <typename T>
int BinaryTree<T>::calculateHeight(TreeNode<T>* root) const
{
    if (!root)
    {
        return 0;
    }
    return 1 + std::max(calculateHeight(root->left.get()), calculateHeight(root->right.get()));
}

template <typename T>
int BinaryTree<T>::getHeight()
{
    height = calculateHeight(root.get());
    return height;
}

template <typename T>
std::vector<std::vector<T>> BinaryTree<T>::levelOrderTraversal()
{
    std::vector<std::vector<T>> levels;
    if (!root)
    {
        return levels;
    }
    
    std::queue<TreeNode<T>*> q;
    q.push(root.get());
    levels.push_back({root->val});
    while (!q.empty())
    {
        const size_t size = q.size();
        std::vector<T> level;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode<T>* front = q.front();
            q.pop();
            if (front->left)
            {
                q.push(front->left.get());
                level.push_back(front->left->val);
            }
            if (front->right)
            {
                q.push(front->right.get());
                level.push_back(front->right->val);
            }
        }
        levels.push_back(level);
    }
    return levels;
}

template class BinaryTree<int>;
template class BinaryTree<double>;
template class BinaryTree<std::string>;
