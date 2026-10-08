//
//  BinaryTreeTest.cpp
//  Trees
//
//  Created by Aaron Sarkar on 2026-09-18.
//

#include <iostream>
#include <algorithm>
#include "BinaryTreeTest.h"
#include "BinaryTree.h"
#include "TreeNode.h"
#include "TreeAlgorithms.h"
#include <vector>
#include <string>
#include <set>
#include <optional>

using namespace std;

template <typename T>
bool BinaryTreeTest<T>::testTreeCreation()
{
    cout << "Creation of Tree: ";
    // First create the vectoral representation of a tree
    vector<optional<int>> treeTest = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    
    //Next, construct tree
    BinaryTree<int> Bt_1(treeTest);
    if (Bt_1.isEmpty())
    {
        cout << " [Failed]" << endl;
        return false;
    }
    cout << " [Passed]" << endl;
    return true;
}

template <typename T>
bool BinaryTreeTest<T>::testInsertNode()
{
    cout << "Insertion of node into BT: ";
    // First create the vectoral representation of a tree
    vector<optional<int>> treeTest = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    
    //Next, construct tree
    BinaryTree<int> Bt_1(treeTest);
    
    //Size before insertion
    const int sizeBefore = Bt_1.getSize();
    
    //Insertion
    Bt_1.insertNode(100);
    
    //Size after insertion
    const int sizeAfter = Bt_1.getSize();
    
    if ((sizeAfter - sizeBefore) != 1)
    {
        cout << " [Failed]" << endl;
        return false;
    }
    
    cout << " [Passed]" << endl;
    return true;
    
}


template <typename T>
bool BinaryTreeTest<T>::testDeleteNode()
{
    cout << "Deletion of node from BT: ";
    // First create the vectoral representation of a tree
    vector<optional<int>> nonEmptyTreeTest = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    vector<optional<int>> emptyTreeTest = {nullopt};
    
    //Next, construct non-empty tree
    BinaryTree<int> Bt_1(nonEmptyTreeTest);
    
    //Next, construct empty tree
    BinaryTree<int> Bt_2(emptyTreeTest);
    
    
    //Size before deletion
    const int sizeBefore = Bt_1.getSize();
    
    //Remove existing node
    Bt_1.remove(7);
    
    //Remove non existing node
    Bt_1.remove(100);
    
    //Size after deletion
    const int sizeAfter = Bt_1.getSize();
    
    std::cout << std::boolalpha;
    
    // We tried to remove an existing and non existing node from non empty tree...therefore the difference should only be 1
    if ((sizeBefore - sizeAfter != 1) || (Bt_2.getSize() != 0))
    {
        cout << " [Failed]...Details Below:" << endl;
        bool nonEmptyFail = (sizeBefore - sizeAfter != 1);
        bool emptyFail = (Bt_2.getSize() != 0);
        cout << "Non Empty Tree deletion test: " << nonEmptyFail << endl;
        cout << "Empty Tree deletion test: " << emptyFail << endl;
        return false;
    }
    
    cout << " [Passed]" << endl;
    return true;

}

template <typename T>
bool BinaryTreeTest<T>::testClearTree()
{
    cout << "Clearing Binary Tree: ";
    // First create the vectoral representation of a tree
    vector<optional<int>> treeTest = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    BinaryTree<int> Bt_1(treeTest);
    Bt_1.clearTree();
    const int sizeAfter = Bt_1.getSize();
    if (sizeAfter != 1)
    {
        cout << " [Failed]" << endl;
        return false;
    }
    cout << " [Passed]" << endl;
    return true;
}

template <typename T>
bool BinaryTreeTest<T>::testInvertBinaryTree()
{
    cout << "Inverting Binary Tree: ";
    // First create the vectoral representation of a tree
    vector<optional<int>> treeTest = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    BinaryTree<int> Bt_1(treeTest);
    // 1. see representation of original
    auto inorderOriginal = TreeAlgos::inorder(Bt_1.getRoot());
    
    // 2. invert and invert again. after store as new representation
    auto Bt_1_inverted = TreeAlgos::invert(Bt_1.getRoot());
    Bt_1_inverted = TreeAlgos::invert(Bt_1.getRoot());
    auto inorderAfterInvert = TreeAlgos::inorder(Bt_1.getRoot());
    
    // 3. check if different. if yes, inversion failed. if no, inversion successful
    if (inorderOriginal != inorderAfterInvert)
    {
        cout << " [Failed]" << endl;
        return false;
    }
    cout << " [Passed]" << endl;
    return true;
}

template <typename T>
bool BinaryTreeTest<T>::testGetHeight()
{
    cout << "Testing Height of Binary Tree: ";
    // First create the vectoral representation of a tree
    vector<optional<int>> treeTest = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    const int actualHeight = 4;
    
    BinaryTree<int> Bt_1(treeTest);
    const int computedHeight = TreeAlgos::getHeight(Bt_1.getRoot());
    
    if (computedHeight != actualHeight)
    {
        cout << " [Failed]" << endl;
        return false;
    }
    cout << " [Passed]" << endl;
    return true;
    
}

template <typename T>
bool BinaryTreeTest<T>::testLowestCommonAncestor()
{
    cout << "Testing LCA of Binary Tree: ";
    // First create the vectoral representation of a tree
    vector<optional<int>> treeTest = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    int actualLCA = 3;
    
    // valid case
    BinaryTree<int> Bt_1(treeTest);
    auto tNode1 = Bt_1.getNode(5);
    auto tNode2 = Bt_1.getNode(1);
    const TreeNode<T>* computedLCA = TreeAlgos::lowestCommonAncestor(Bt_1.getRoot(), tNode1, tNode2);
    int testedaLCA = computedLCA->val;
    if (testedaLCA != actualLCA)
    {
        cout << " [Failed]" << endl;
        return false;
    }
    
    // inavlid case..when nodes are not in Tree, simply return root
    tNode1 = Bt_1.getNode(500);
    tNode2 = Bt_1.getNode(100);
    computedLCA = TreeAlgos::lowestCommonAncestor(Bt_1.getRoot(), tNode1, tNode2);
    testedaLCA = computedLCA->val;
    if (testedaLCA != actualLCA)
    {
        cout << " [Failed]" << endl;
        return false;
    }
    cout << " [Passed]" << endl;
    return true;
}

template <typename T>
bool BinaryTreeTest<T>::testMaxPathSum()
{
    cout << "Testing Max Path Sum of Binary Tree: ";
    // First create the vectoral representation of a tree
    vector<optional<int>> treeTest = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    int actualSum = 26;
    BinaryTree<int> Bt_1(treeTest);
    int computedSum = TreeAlgos::getMaxPathSum(Bt_1.getRoot());
    if (actualSum != computedSum)
    {
        cout << " [Failed]" << endl;
        return false;
    }
    cout << " [Passed]" << endl;
    return true;
}

template <typename T>
bool BinaryTreeTest<T>::testMaxDiameter()
{
    cout << "Testing Max Diameter of Binary Tree: ";
    // First create the vectoral representation of a tree
    vector<optional<int>> treeTest = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    int actualDiam = 5;
    BinaryTree<int> Bt_1(treeTest);
    int computedDiam = TreeAlgos::getMaxDiameter(Bt_1.getRoot());
    if (actualDiam != computedDiam)
    {
        cout << " [Failed]" << endl;
        return false;
    }
    cout << " [Passed]" << endl;
    return true;
}

template <typename T>
bool BinaryTreeTest<T>::testRootToLeafPathsThatSumTo()
{
    cout << "Testing root to leaf paths that sum to: ";
    // First create the vectoral representation of a tree
    vector<optional<int>> treeTest = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    int target1 = 14;
    int target2 = 1000;
    BinaryTree<int> Bt_1(treeTest);
    
    auto paths = TreeAlgos::rootToLeafPathsThatSumTo(Bt_1.getRoot(), target1);
    set<vector<int>> solutionSet = {{3,5,6}, {3,5,2,4}};
    for (const auto& path: paths)
    {
        if (!solutionSet.contains(path))
        {
            cout << " [Failed]" << endl;
            return false;
        }
    }
    
    // should be empty since there is no path that sums to 1000
    paths = TreeAlgos::rootToLeafPathsThatSumTo(Bt_1.getRoot(), target2);
    if (paths.size() > 0)
    {
        cout << " [Failed]" << endl;
        return false;
    }
    
    cout << " [Passed]" << endl;
    return true;
}

template <typename T>
bool BinaryTreeTest<T>::testAllPathsThatSumTo()
{
    cout << "Testing all paths that sum to: ";
    // First create the vectoral representation of a tree
    vector<optional<int>> treeTest = {10,5,-3,3,2,nullopt,11,3,-2,nullopt,1};
    int target1 = 8;
    int target2 = 1000;
    int expectedNumPaths = 3;
    BinaryTree<int> Bt_1(treeTest);
    
    auto numPaths = TreeAlgos::allPathsThatSumTo(Bt_1.getRoot(), target1);
    if (numPaths != expectedNumPaths)
    {
        cout << " [Failed]" << endl;
        return false;
    }
    
    // No paths sum up to 1000
    numPaths = TreeAlgos::allPathsThatSumTo(Bt_1.getRoot(), target2);
    if (numPaths != 0)
    {
        cout << " [Failed]" << endl;
        return false;
    }

    cout << " [Passed]" << endl;
    return true;
}

template <typename T>
bool BinaryTreeTest<T>::testMaxSumBST()
{
    cout << "Testing max sum BST: ";
    // First create the vectoral representation of a tree
    vector<optional<int>> treeTest = {1,4,3,2,4,2,5,nullopt,nullopt,nullopt,nullopt,nullopt,nullopt,4,6};
    int maxSum = 20;
    BinaryTree<int> Bt_1(treeTest);
    
    auto computedSum = TreeAlgos::getMaxSum(Bt_1.getRoot());
    if (computedSum != maxSum)
    {
        cout << " [Failed]" << endl;
        return false;
    }
    
    treeTest = {-4,-2,-5};
    maxSum = 0;
    BinaryTree<int> Bt_2(treeTest);
    computedSum = TreeAlgos::getMaxSum(Bt_2.getRoot());
    if (computedSum != 0)
    {
        cout << " [Failed]" << endl;
        return false;
    }
    
    cout << " [Passed]" << endl;
    return true;
}

template <typename T>
bool BinaryTreeTest<T>::testInorderTraversal()
{
    cout << "Testing Inorder Traversal (recursive): ";
    // First create the vectoral representation of a tree
    vector<optional<int>> treeTest = {3,2,4,1};
    BinaryTree<int> Bt_1(treeTest);
    auto inorderVec = TreeAlgos::inorder(Bt_1.getRoot());
    if (!is_sorted(inorderVec.begin(), inorderVec.end()))
    {
        cout << " [Failed]" << endl;
        return false;
    }
    cout << " [Passed]" << endl;
    return true;
}

template <typename T>
bool BinaryTreeTest<T>::testSmallestRootToLeafString()
{
    cout << "Testing Smallest Root To Leaf String: ";
    // First create the vectoral representation of a tree
    vector<optional<char>> treeTest = {0,1,2,3,4,3,4};
    BinaryTree<char> Bt_1(treeTest);
    auto lexSmallestString = TreeAlgos::smallestRootToLeafString(Bt_1.getRoot());
    if (lexSmallestString != "dba")
    {
        cout << " [Failed]" << endl;
        return false;
    }
    cout << " [Passed]" << endl;
    return true;
}


template <typename T>
bool BinaryTreeTest<T>::executeTest()
{
    auto executuonStatus = testTreeCreation() && testInsertNode() && testDeleteNode() && testClearTree() && testInvertBinaryTree() && testGetHeight() && testLowestCommonAncestor() && testMaxPathSum() && testMaxDiameter() && testRootToLeafPathsThatSumTo() && testAllPathsThatSumTo() && testMaxSumBST() && testInorderTraversal() && testSmallestRootToLeafString();
    
    if (!executuonStatus)
    {
        cout << " [Unit Tests Failed]" << endl;
        return false;
    }
    cout << " [Unit Test Passed]" << endl;
    return true;

}

template class BinaryTreeTest<int>;
