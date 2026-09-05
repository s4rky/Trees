//
//  TreeNode.h
//  Trees
//
//  Created by Aaron Sarkar on 2026-09-05.
//
#pragma once
#include <memory>

template <typename T>
class TreeNode
{
public:
    TreeNode(T val) : val(val), left(nullptr), right(nullptr) {}
    T val;
    std::unique_ptr<TreeNode<T>> left;
    std::unique_ptr<TreeNode<T>> right;
};

