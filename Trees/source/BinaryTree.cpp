//
//  BinaryTree.cpp
//  Trees
//  Implementation of Binary Tree Class
//  Created by Aaron Sarkar on 2026-09-05.
//


#include "BinaryTree.h"
#include <queue>
#include <limits>
#include <algorithm>
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
            levelOrderVector.push_back(node->val);
            if (p2 < nodes.size() && nodes[p2].has_value())
            {
                node->left = std::make_unique<TreeNode<T>>(nodes[p2].value());
                q.push(node->left.get());
                nodeSet.insert(node->left.get());
            }
            if (p3 < nodes.size() && nodes[p3].has_value())
            {
                node->right = std::make_unique<TreeNode<T>>(nodes[p3].value());
                q.push(node->right.get());
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
std::pair<bool,TreeNode<T>*> BinaryTree<T>::search(TreeNode<T>* root, const T& val) const
{
    if (!root)
    {
        return {false, nullptr};
    }
    if (root->val == val)
    {
        return {true, root};
    }
    auto left = search(root->left.get(), val);
    bool inLeft = left.first;
    if (inLeft)
    {
        return {inLeft, left.second};
    }
    
    auto right = search(root->right.get(), val);
    bool inRight = right.first;
    if (inRight)
    {
        return {inRight, right.second};
    }
    return {false, nullptr};
}

template <typename T>
TreeNode<T>* BinaryTree<T>::getNode(const T& val) const
{
    return search(root.get(), val).second;
}


template <typename T>
TreeNode<T>* BinaryTree<T>::invertTree(TreeNode<T>* root)
{
    if (!root)
    {
        return nullptr;
    }
    std::swap(root->left, root->right);
    invertTree(root->left.get());
    invertTree(root->right.get());
    return root;
}

template <typename T>
void BinaryTree<T>::invertBinaryTree()
{
    invertTree(root.get());
}

template <typename T>
void BinaryTree<T>::insertNode(const T& val)
{
    auto node = std::make_unique<TreeNode<T>>(val);
    if (!root)
    {
        root = std::move(node);
        nodeSet.insert(root.get());
        levelOrderVector.push_back(root->val);
        return;
    }
    std::queue<TreeNode<T>*> q;
    q.push(root.get());
    while (!q.empty())
    {
        const size_t size = q.size();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode<T>* front = q.front();
            q.pop();
            
            if (!front->left)
            {
                front->left = std::move(node);
                nodeSet.insert(front->left.get());
                levelOrderVector.push_back(front->left->val);
                return;
            }
            if (!front->right)
            {
                front->right = std::move(node);
                nodeSet.insert(front->right.get());
                levelOrderVector.push_back(front->right->val);
                return;
            }
            if (front->left)
            {
                q.push(front->left.get());
            }
            if (front->right)
            {
                q.push(front->right.get());
            }
        }
    }
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
const bool BinaryTree<T>::isEmpty() const
{
    return nodeSet.empty();
}

template <typename T>
const int BinaryTree<T>::getSize() const
{
    return static_cast<int>(levelOrderVector.size());
}

template <typename T>
void BinaryTree<T>::deleteAllExceptRoot(TreeNode<T>* root)
{
    if (!root)
    {
        return;
    }
    deleteAllExceptRoot(root->left.get());
    deleteAllExceptRoot(root->right.get());
    if (nodeSet.size() > 1)
    {
        nodeSet.erase(root->left.get());
        nodeSet.erase(root->right.get());
    }
    if (levelOrderVector.size() > 1)
    {
        levelOrderVector.pop_back();
    }
    root->left = nullptr;
    root->right = nullptr;
}
template <typename T>
void BinaryTree<T>::clearTree()
{
    deleteAllExceptRoot(root.get());
}

template <typename T>
void BinaryTree<T>::remove(const T& val)
{
    auto toDelete = getNode(val);
    if (!root || !toDelete)
    {
        return;
    }
    std::queue<TreeNode<T>*> q;
    q.push(root.get());
    TreeNode<T>* rightMost = root.get();
    TreeNode<T>* parent = root.get();
    
    while (!q.empty())
    {
        const size_t size = q.size();
        for (size_t i = 0; i < size; i++)
        {
            auto curr = q.front();
            rightMost = curr;
            q.pop();
            // last node with left or right child is the parent
            if (curr->left || curr->right)
            {
                parent = curr;
            }
            if (curr->left)
            {
                q.push(curr->left.get());
            }
            if (curr->right)
            {
                q.push(curr->right.get());
            }
        }
    }
    toDelete->val = rightMost->val;
    if (parent->left.get() == rightMost)
    {
        parent->left = nullptr;
    }
    else
    {
        parent->right = nullptr;
    }
    nodeSet.erase(toDelete);
    std::erase(levelOrderVector, toDelete->val);
}


template class BinaryTree<int>;
template class BinaryTree<double>;
template class BinaryTree<std::string>;
