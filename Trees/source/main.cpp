//
//  main.cpp
//  Trees
//
//  Created by Aaron Sarkar on 2026-09-05.
//

#include <iostream>
#include "TreeNode.h"
#include "BinaryTree.h"
#include <vector>
#include <string>
#include <optional>

using namespace std;

int main(int argc, const char * argv[])
{
    vector<optional<int>> treeTest = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    BinaryTree<int> Bt_1(treeTest);
    
    auto node1 = Bt_1.getNode(5);
    auto node2 = Bt_1.getNode(4);
    auto ancestor = Bt_1.lowestCommonAncestor(node1, node2);
    cout << "LCA: " << ancestor->val << endl;
    cout << "Max Diameter: " << Bt_1.getMaxDiameter() << endl;
    cout << "Max Path Sum: " << Bt_1.getMaxPathSum() << endl;
    cout << "Max Height: " << Bt_1.getHeight() << endl;
    cout << "Inorder Traversal: " << Bt_1.traverse(BinaryTree<int>::Traversal::Inorder) << endl;
    cout << "Preorder Traversal: " << Bt_1.traverse(BinaryTree<int>::Traversal::Preorder) << endl;
    cout << "Postorder Traversal: " << Bt_1.traverse(BinaryTree<int>::Traversal::Postorder) << endl;
    cout << "Level Order Traversal: " << Bt_1.traverse(BinaryTree<int>::Traversal::Levelorder) << endl;
    
    cout << "BFS before insertion of value: " << endl;
    auto levels = Bt_1.levelOrderTraversal();
    for (const auto& level: levels)
    {
        cout << "[" << " ";
        for (const auto& node: level)
        {
            cout << node << ", ";
        }
        cout << "]" << endl;
        
    }
    Bt_1.insertNode(20);
    cout << "BFS after insertion of value: " << endl;
    levels = Bt_1.levelOrderTraversal();
    for (const auto& level: levels)
    {
        cout << "[" << " ";
        for (const auto& node: level)
        {
            cout << node << ", ";
        }
        cout << "]" << endl;
        
    }
    return 0;
}
