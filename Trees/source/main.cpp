//
//  main.cpp
//  Trees
//
//  Created by Aaron Sarkar on 2026-09-05.
//

#include <iostream>
#include "TreeNode.h"
#include "BinaryTree.h"
#include "TreeAlgorithms.h"
#include <vector>
#include <string>
#include <optional>

using namespace std;

int main(int argc, const char * argv[])
{
    vector<optional<int>> treeTest = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    BinaryTree<int> Bt_1(treeTest);
    
    
    cout << "---TEST CLEAR TREE---" << endl;
    Bt_1.printTree();
    Bt_1.clearTree();
    Bt_1.printTree();
    int heightBt_1 = TreeAlgos::getHeight(Bt_1.getRoot());
    cout << "Cleared Successfully: " << (heightBt_1 == 1) << endl;
    
    
    cout << "----TEMPLATED VERSION---" << endl;
    vector<optional<int>> templateTreeTest = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    BinaryTree<int> BT(templateTreeTest);
    int height = TreeAlgos::getHeight(BT.getRoot());
    cout << "Height: " << height << endl;
    auto tNode1 = BT.getNode(10);
    auto tNode2 = BT.getNode(13);
    auto LCA = TreeAlgos::lowestCommonAncestor(BT.getRoot(), tNode1, tNode2);
    cout << "LCA: " << LCA->val << endl;
    auto diameter = TreeAlgos::getMaxDiameter(BT.getRoot());
    cout << "Diameter: " << diameter << endl;
    auto maxPathSum = TreeAlgos::getMaxPathSum(BT.getRoot());
    cout << "Max Path Sum: " << maxPathSum << endl;
    auto paths = TreeAlgos::pathsThatSumTo(BT.getRoot(), 14);
    cout << "---PATHS THAT SUM TO A TARGET TEST---" << endl;
    for (const auto& path: paths)
    {
        for (const auto& val: path)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "----TEST SAME TREE---" << endl;
    std::cout << std::boolalpha;
    vector<optional<int>> treeTest4 = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    BinaryTree<int> Bt_4(treeTest4);
    vector<optional<int>> treeTest5 = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    BinaryTree<int> Bt_5(treeTest5);
    auto same = TreeAlgos::sameTree(Bt_4.getRoot(), Bt_4.getRoot());
    if (same)
    {
        cout << "The 2 compared Trees are identical" << endl;
    }
    else
    {
        cout << "The 2 compared Trees are not the same" << endl;
    }
    
    cout << "----TRAVERSAL TEST----" << endl;
    auto traversal = TreeAlgos::levelOrderTraversal(BT.getRoot());
    for (const auto& level: traversal)
    {
        cout << "[";
        for (const auto& val: level)
        {
            cout << val << " ";
        }
        cout << "]";
        cout << endl;
    }
    cout << endl;
    
    return 0;
}
