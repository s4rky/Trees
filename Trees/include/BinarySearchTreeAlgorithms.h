//
//  BinarySearchTreeAlgorithms.h
//  Trees
//
//  Created by Aaron Sarkar on 2026-10-08.
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
#include <unordered_map>

namespace BinarySearchTreeAlgos
{

template <typename T>
bool isValidTopDown(const TreeNode<T>* root);

template <typename T>
bool isValidBottomUp(const TreeNode<T>* root);

template <typename T>
bool isValidInorderCheck(const TreeNode<T>* root);

} // namespace BinarySearchTreeAlgos

#include "../source/BinarySearchTreeAlgorithms.tpp"
