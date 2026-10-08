//
//  BinarySearchTreeTest.h
//  Trees
//
//  Created by Aaron Sarkar on 2026-10-08.
//

#include "TreeNode.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "TreeAlgorithms.h"
#include "BinarySearchTreeAlgorithms.h"

template <typename T>
class BinarySearchTreeTest
{
public:
    bool executeTest();
    
private:
    bool testCreation();
    bool testInsert();
    bool testDelete();
};

