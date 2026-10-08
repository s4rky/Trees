//
//  BinarySearchTree.cpp
//  Trees
//
//  Created by Aaron Sarkar on 2026-10-08.
//

#include "BinarySearchTree.h"
#include <iostream>

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const std::vector<const T&> nodes)
{
    if (nodes.size() == 0)
    {
        return;
    }
    root = std::make_unique<TreeNode<T>>(nodes[0]);
    for (int i = 1; i < nodes.size(); i++)
    {
        insert(root, nodes[i].value());
    }
}

template <typename T>
void BinarySearchTree<T>::insert(std::unique_ptr<TreeNode<T>>& root, const T& val)
{
    if (!root)
    {
        root = std::make_unique<TreeNode<T>>(val);
        return;
    }
    
    if (root->val > val)
    {
        insert(root->right, val);
    }
    else if (root->val < val)
    {
        insert(root->left, val);
    }
    else
    {
        return;
    }
}

template <typename T>
void BinarySearchTree<T>::insertIntoBST(std::unique_ptr<TreeNode<T>>& root, const T& val)
{
    insert(root, val);
}

template class BinarySearchTree<int>;
template class BinarySearchTree<double>;
template class BinarySearchTree<std::string>;
template class BinarySearchTree<char>;








