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
bool BinaryTree<T>::traverseForPath(const TreeNode<T>* root, const TreeNode<T>* target, std::vector<const TreeNode<T>*>& path) const
{
    if (!root)
    {
        return false;
    }
    if (root == target)
    {
        path.push_back(root);
        return true;
    }
    path.push_back(root);
    if (traverseForPath(root->left.get(), target, path) || traverseForPath(root->right.get(), target, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}

template <typename T>
std::pair<bool,const TreeNode<T>*> BinaryTree<T>::search(const TreeNode<T>* root, const T& val) const
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
const TreeNode<T>* BinaryTree<T>::getNode(const T& val) const
{
    return search(root.get(), val).second;
}

template <typename T>
const TreeNode<T>* BinaryTree<T>::lowestCommonAncestor(const TreeNode<T>* node1, const TreeNode<T>* node2) const
{
    if (!root || !inTree(node1) || !inTree(node2))
    {
        return nullptr;
    }
    std::vector<const TreeNode<T>*> node1Vec;
    traverseForPath(root.get(), node1, node1Vec);
    std::vector<const TreeNode<T>*> node2Vec;
    traverseForPath(root.get(), node2, node2Vec);
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
    if (!root)
    {
        return;
    }
    auto node = std::make_unique<TreeNode<T>>(val);
    
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

template <typename T>
int BinaryTree<T>::calculateMaxDiameter(const TreeNode<T> *root)
{
    if (!root)
    {
        return -1;
    }
    auto left = 1 + calculateMaxDiameter(root->left.get());
    auto right = 1 + calculateMaxDiameter(root->right.get());
    int currMax = left + right;
    int max_l_r = std::max(left, right);
    maxDiam = std::max(currMax, maxDiam);
    return max_l_r;
}
template <typename T>
const int BinaryTree<T>::getMaxDiameter()
{
    maxDiam = 0;
    calculateMaxDiameter(root.get());
    return maxDiam;
}

template <typename T>
T BinaryTree<T>::calculateMaxPathSum(const TreeNode<T> *root)
{

    if (!root)
    {
        return T{};
    }
    auto left = calculateMaxPathSum(root->left.get());
    auto right = calculateMaxPathSum(root->right.get());
    auto totalSum = left + right + root->val;
    maxPathSum = std::max({root->val, maxPathSum, totalSum, root->val + left, root->val + right});
    return std::max({root->val + left, root->val + right, root->val});

}

template <typename T>
const T BinaryTree<T>::getMaxPathSum()
{
    maxPathSum = std::numeric_limits<T>::lowest();
    calculateMaxPathSum(root.get());
    return maxPathSum;
}

template <typename T>
void BinaryTree<T>::inorder(const TreeNode<T>* root, std::vector<const TreeNode<T>*> &inorderVec)
{
    if (!root)
    {
        return;
    }
    inorder(root->left.get(), inorderVec);
    inorderVec.push_back(root);
    inorder(root->right.get(), inorderVec);
}
template <typename T>
void BinaryTree<T>::preorder(const TreeNode<T>* root, std::vector<const TreeNode<T>*> &preorderVec)
{
    if (!root)
    {
        return;
    }
    preorderVec.push_back(root);
    preorder(root->left.get(), preorderVec);
    preorder(root->right.get(), preorderVec);
}
template <typename T>
void BinaryTree<T>::postorder(const TreeNode<T>* root, std::vector<const TreeNode<T>*> &postorderVec)
{
    if (!root)
    {
        return;
    }
    postorder(root->left.get(), postorderVec);
    postorder(root->right.get(), postorderVec);
    postorderVec.push_back(root);
}

template <typename T>
std::vector<T> BinaryTree<T>::inorderTraversal()
{
    inorderVec.clear();
    inorder(root.get(),inorderVec);
    
    std::vector<T> values;
    
    for (const auto* it: inorderVec)
    {
        values.push_back(it->val);
    }
    return values;
}

template <typename T>
std::vector<T> BinaryTree<T>::postorderTraversal()
{
    postorderVec.clear();
    postorder(root.get(),postorderVec);
    
    std::vector<T> values;
    
    for (const auto* it: postorderVec)
    {
        values.push_back(it->val);
    }
    return values;
}

template <typename T>
std::vector<T> BinaryTree<T>::preorderTraversal() 
{
    preorderVec.clear();
    preorder(root.get(),preorderVec);
    
    std::vector<T> values;
    
    for (const auto* it: preorderVec)
    {
        values.push_back(it->val);
    }
    return values;
}

template <typename T>
std::string BinaryTree<T>::vecToString(const std::vector<T> vec)
{
    if (vec.empty())
    {
        return "";
    }
    std::ostringstream oss;
    
    for (size_t i = 0; i < vec.size(); i++)
    {
        oss << vec[i];
        if (i < vec.size() - 1)
        {
            oss << ", ";
        }
        
    }
    return oss.str();
}
template <typename T>
std::string BinaryTree<T>::traverse(const Traversal traversalType)
{
    switch (traversalType)
    {
        case Traversal::Inorder:
        {
            auto In = inorderTraversal();
            return vecToString(In);
        }
        case Traversal::Preorder:
        {
            auto Pre = preorderTraversal();
            return vecToString(Pre);
        }

        case Traversal::Postorder:
        {
            auto Post = postorderTraversal();
            return vecToString(Post);
        }
        case Traversal::Levelorder:
        {
            return vecToString(levelOrderVector);
        }
        default:
            return "";
    }
}

template class BinaryTree<int>;
template class BinaryTree<double>;
template class BinaryTree<std::string>;
