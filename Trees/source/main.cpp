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
    Bt_1.printTree();
    auto levels = Bt_1.levelOrderTraversal();
    for (const auto& level: levels)
    {
        cout << "[" << "";
        for (const auto& node: level)
        {
            
            cout << node << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
