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
    vector<optional<int>> treeTest = {1,2,3,nullopt,nullopt,4,5,nullopt,nullopt,nullopt,nullopt};
    BinaryTree<int> Bt_1(treeTest);
    Bt_1.printTree();
    cout << Bt_1.getHeight() << endl;
    return 0;
}
