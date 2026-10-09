//
//  BinarySearchTree.cpp
//  Trees
//
//  Created by Aaron Sarkar on 2026-10-08.
//

#include "BinarySearchTree.h"
#include <iostream>

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const std::vector<T>& nodes)
{
    if (nodes.size() == 0)
    {
        return;
    }
    root = std::make_unique<TreeNode<T>>(nodes[0]);
    for (int i = 1; i < nodes.size(); i++)
    {
        insert(root, nodes[i]);
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
        insert(root->left, val);
    }
    else if (root->val < val)
    {
        insert(root->right, val);
    }
    else
    {
        return;
    }
}

template <typename T>
void BinarySearchTree<T>::insertIntoBST(const T& val)
{
    insert(root, val);
}

template <typename T>
void BinarySearchTree<T>::remove(std::unique_ptr<TreeNode<T>>& root, const T& val)
{
    if (!root)
    {
        return;
    }
    
    // deletion
    if (root->val == val)
    {
        // leaf
        if (!root->left && !root->right)
        {
            root.reset();
        }
        // only child
        else if (!root->left || !root->right)
        {
            root = (root->left) ? std::move(root->left) : std::move(root->right);
        }
        // siblings
        else
        {
            TreeNode<T>* rightMin = root->right.get();
            while (rightMin->left)
            {
                rightMin = rightMin->left.get();
            }
            root->val = rightMin->val;
            remove(root->right, rightMin->val);
        }
        
    }
    // traversal
    else if (root->val < val)
    {
        remove(root->right, val);
    }
    else
    {
        remove(root->left, val);
    }
    
}

template <typename T>
void BinarySearchTree<T>::deleteFromBST(const T& val)
{
    remove(root, val);
}


template class BinarySearchTree<int>;
template class BinarySearchTree<double>;
template class BinarySearchTree<std::string>;
template class BinarySearchTree<char>;








