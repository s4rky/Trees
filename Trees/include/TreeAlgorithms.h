//
//  TreeAlgorithms.h
//  Trees
//
//  Created by Aaron Sarkar on 2026-09-11.
//

#pragma once
#include "TreeNode.h"
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <sstream>
#include <limits>

namespace TreeAlgos
{
template <typename T>
struct BSTcandidate
{
    bool isValid;
    T minVal;
    T maxVal;
    T sum;
};

template <typename T>
int getHeight(const TreeNode<T>* root);

template <typename T>
const TreeNode<T>* lowestCommonAncestor(const TreeNode<T>* root, const TreeNode<T>* node1, const TreeNode<T>* node2);

template <typename T>
const int getMaxDiameter(const TreeNode<T> *root);

template <typename T>
const T getMaxPathSum(const TreeNode<T> *root);

template <typename T>
TreeNode<T>* invertTree(TreeNode<T>* root);

template <typename T>
std::vector<std::vector<T>> pathsThatSumTo(const TreeNode<T>* root, const T& target);

template <typename T>
std::vector<T> inorder(const TreeNode<T>* root);

template <typename T>
std::vector<T> preorder(const TreeNode<T>* root);

template <typename T>
std::vector<T> postorder(const TreeNode<T>* root);

template <typename T>
std::vector<std::vector<T>> levelOrderTraversal(const TreeNode<T>* root);

template <typename T>
void flattenBinaryTree(TreeNode<T>* root);

template <typename T>
std::vector<T> morrisInorder(TreeNode<T>* root);

template <typename T>
T maxSumBST(const TreeNode<T>* root);

} // namespace TreeAlgos

#include "../source/TreeAlgorithms.tpp"
