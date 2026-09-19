//
//  BinaryTreeTest.h
//  Trees
//
//  Created by Aaron Sarkar on 2026-09-18.
//
#include "TreeNode.h"
#include "BinaryTree.h"
#include "TreeAlgorithms.h"

template <typename T>
class BinaryTreeTest
{
public:
    
    bool executeTest();
    
private:
    
    bool testTreeCreation();
    
    bool testInsertNode();
    
    bool testDeleteNode();
    
    bool testClearTree();
    
    bool testInvertBinaryTree();
    
    bool testGetHeight();
    
    bool testLowestCommonAncestor();
    
    bool testGetMaxDiameter();
    
    bool getMaxPathSum();
    
    bool testInvertTree();
    
    bool testRootToLeafPathsThatSumTo();
    
    bool testInorderTraversal();
    
    bool testPreorderTraversal();
    
    bool testPostorderTraversal();
    
    bool testLevelOrderTraversal();
    
    bool testFlattenBinaryTree();
    
    bool testMorrisInorder();
    
    bool testMaxSumBST();
    
    bool testAllPathsThatSumTo();

    
};
