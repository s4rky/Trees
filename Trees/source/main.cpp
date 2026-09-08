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
    
    int target = 14;
    auto paths = Bt_1.pathsThatSumTo(target);
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
    vector<optional<int>> treeTest2 = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    BinaryTree<int> Bt_2(treeTest2);
    cout << Bt_1.isSameAs(Bt_2.getRoot()) << endl;
    vector<optional<int>> treeTest3 = {3,5,1,6,2,0,8,nullopt,nullopt,7,7};
    BinaryTree<int> Bt_3(treeTest3);
    cout << Bt_1.isSameAs(Bt_3.getRoot()) << endl;
    
    cout << "---TEST DELETION---" << endl;
    cout << "Before deletion (inorder): " << Bt_1.traverse(BinaryTree<int>::Traversal::Inorder) << endl;
    Bt_1.remove(5);
    cout << "After deletion (inorder): " << Bt_1.traverse(BinaryTree<int>::Traversal::Inorder) << endl;
    
    
    cout << "---TEST CLEAR TREE---" << endl;
    Bt_1.printTree();
    Bt_1.clearTree();
    Bt_1.printTree();
    cout << "Cleared Successfully: " << (Bt_1.getHeight() == 1) << endl;
    
    return 0;
}
