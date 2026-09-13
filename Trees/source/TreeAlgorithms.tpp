#pragma once

namespace TreeAlgos
{

/**
 The detail namespace handles private helper methods so to never have detailed implementations visible through the public API.
 */
namespace detail
{
    template <typename T>
    bool traverseForPath(const TreeNode<T>* root, const TreeNode<T>* target, std::vector<const TreeNode<T>*>& path)
    {
        if (!root)
        {
            return false;
        }
        if (root == target)
        {
            path.push_back(root);
            return true;
        }
        path.push_back(root);
        if (traverseForPath(root->left.get(), target, path) || traverseForPath(root->right.get(), target, path))
        {
            return true;
        }
        path.pop_back();
        return false;
    }

    template <typename T>
    const TreeNode<T>* findLowestCommonAncestor(const TreeNode<T>* root, const TreeNode<T>* node1, const TreeNode<T>* node2)
    {
        std::vector<const TreeNode<T>*> node1Vec;
        std::vector<const TreeNode<T>*> node2Vec;
        if (!traverseForPath(root, node1, node1Vec) || !traverseForPath(root, node2, node2Vec))
        {
            
            return nullptr;
        }
        size_t n1Ptr = 0;
        size_t n2Ptr = 0;
        size_t n1Size = node1Vec.size();
        size_t n2Size = node2Vec.size();
        
        while ((n1Ptr + 1 < n1Size && n2Ptr + 1 < n2Size) && (node1Vec[n1Ptr + 1] == node2Vec[n2Ptr + 1]))
        {
            n1Ptr++;
            n2Ptr++;
        }
        
        return node1Vec[n1Ptr];
    }

    template <typename T>
    int calculateMaxDiameter(const TreeNode<T> *root, int& maxDiam)
    {
        if (!root)
        {
            return -1;
        }
        auto left = 1 + calculateMaxDiameter(root->left.get(), maxDiam);
        auto right = 1 + calculateMaxDiameter(root->right.get(), maxDiam);
        int currMax = left + right;
        int max_l_r = std::max(left, right);
        maxDiam = std::max(currMax, maxDiam);
        return max_l_r;
    }

    template <typename T>
    T calculateMaxPathSum(const TreeNode<T> *root, T& maxPathSum)
    {
        if (!root)
        {
            return T{};
        }
        auto left = calculateMaxPathSum(root->left.get(), maxPathSum);
        auto right = calculateMaxPathSum(root->right.get(), maxPathSum);
        auto totalSum = left + right + root->val;
        maxPathSum = std::max({root->val, maxPathSum, totalSum, root->val + left, root->val + right});
        return std::max({root->val + left, root->val + right, root->val});
    }

    template <typename T>
    void constructPathForTargetSum(const TreeNode<T>* root, const T& targetSum, std::vector<T>& path, std::vector<std::vector<T>>& paths, T currSum)
    {
        if (!root)
        {
            return;
        }
        currSum += root->val;
        path.push_back(root->val);
        if (!root->left && !root->right)
        {
            if (currSum == targetSum)
            {
                paths.push_back(path);
            }
            path.pop_back();
            return;
        }
        constructPathForTargetSum(root->left.get(), targetSum, path, paths, currSum);
        constructPathForTargetSum(root->right.get(), targetSum, path, paths, currSum);
        path.pop_back();
    }

    template <typename T>
    bool isSameTree(const TreeNode<T>* root1, const TreeNode<T>* root2)
    {
        if (!root1 && !root2)
        {
            return true;
        }
        bool isImbalanced = (!root1 || !root2);
        bool diffValues = (root1 && root2) && (root1->val != root2->val);
        if (isImbalanced || diffValues)
        {
            return false;
        }
        return isSameTree(root1->left.get(), root2->left.get()) && isSameTree(root1->right.get(), root2->right.get());
    }

    template <typename T>
    void inorderTraversal(const TreeNode<T>* root, std::vector<const TreeNode<T>*> &inorderVec)
    {
        if (!root)
        {
            return;
        }
        inorderTraversal(root->left.get(), inorderVec);
        inorderVec.push_back(root);
        inorderTraversal(root->right.get(), inorderVec);
    }

    template <typename T>
    void preorderTraversal(const TreeNode<T>* root, std::vector<const TreeNode<T>*> &preorderVec)
    {
        if (!root)
        {
            return;
        }
        preorderVec.push_back(root);
        preorderTraversal(root->left.get(), preorderVec);
        preorderTraversal(root->right.get(), preorderVec);
    }
    template <typename T>
    void postorderTraversal(const TreeNode<T>* root, std::vector<const TreeNode<T>*> &postorderVec)
    {
        if (!root)
        {
            return;
        }
        postorderTraversal(root->left.get(), postorderVec);
        postorderTraversal(root->right.get(), postorderVec);
        postorderVec.push_back(root);
    }
    
    template <typename T>
    void BreadthFirstSearch(const TreeNode<T>* root, std::vector<std::vector<T>>& levels)
    {
        if (!root)
        {
            return;
        }
        
        std::queue<const TreeNode<T>*> q;
        q.push(root);
        levels.push_back({root->val});
        
        while (!q.empty())
        {
            const size_t size = q.size();
            std::vector<T> level;
            for (size_t i = 0; i < size; i++)
            {
                const TreeNode<T>* front = q.front();
                q.pop();
                if (front->left)
                {
                    q.push(front->left.get());
                    level.push_back(front->left->val);
                }
                if (front->right)
                {
                    q.push(front->right.get());
                    level.push_back(front->right->val);
                }
            }
            levels.push_back(level);
        }
    }
}

/**
 Public APIs.
 */
template <typename T>
int getHeight(const TreeNode<T>* root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + std::max(getHeight(root->left.get()), getHeight(root->right.get()));
}

template <typename T>
const TreeNode<T>* lowestCommonAncestor(const TreeNode<T>* root, const TreeNode<T>* node1, const TreeNode<T>* node2)
{
    if (!root)
    {
        std::cout << "Querying a null root" << std::endl;
        return nullptr;
    }
    const TreeNode<T>* LCA = detail::findLowestCommonAncestor(root, node1, node2);
    
    if (!LCA)
    {
        std::cout << "(At least 1 of) The queried nodes are invalid" << std::endl;
        std::cout << "Returning Root..." << std::endl;
        return root;
    }
    return LCA;
}
template <typename T>
const int getMaxDiameter(const TreeNode<T>* root)
{
    int maxDiam = 0;
    detail::calculateMaxDiameter(root, maxDiam);
    return maxDiam;
}

template <typename T>
const T getMaxPathSum(const TreeNode<T>* root)
{
    T maxPathSum = std::numeric_limits<T>::lowest();
    detail::calculateMaxPathSum(root, maxPathSum);
    return maxPathSum;
}

template <typename T>
std::vector<std::vector<T>> pathsThatSumTo(const TreeNode<T>* root, const T& target)
{
    std::vector<std::vector<T>> paths;
    if (!root)
    {
        return paths;
    }
    std::vector<T> path;
    detail::constructPathForTargetSum(root, target, path, paths, T{});
    return paths;
}

template <typename T>
bool sameTree(const TreeNode<T>* root1, const TreeNode<T>* root2)
{
    return detail::isSameTree(root1, root2);
}

template <typename T>
std::vector<T> inorder(const TreeNode<T>* root)
{
    std::vector<const TreeNode<T>*> inorderVec;
    detail::inorderTraversal(root, inorderVec);
    
    std::vector<T> values;
    
    for (const auto it: inorderVec)
    {
        values.push_back(it->val);
    }
    return values;
}

template <typename T>
std::vector<T> preorder(const TreeNode<T>* root)
{
    std::vector<const TreeNode<T>*> preorderVec;
    detail::preorderTraversal(root, preorderVec);
    
    std::vector<T> values;
    
    for (const auto it: preorderVec)
    {
        values.push_back(it->val);
    }
    return values;
}

template <typename T>
std::vector<T> postorder(const TreeNode<T>* root)
{
    std::vector<const TreeNode<T>*> postorderVec;
    detail::postorderTraversal(root, postorderVec);
    
    std::vector<T> values;
    
    for (const auto it: postorderVec)
    {
        values.push_back(it->val);
    }
    return values;
}

template <typename T>
std::vector<std::vector<T>> levelOrderTraversal(const TreeNode<T>* root)
{
    std::vector<std::vector<T>> levels;
    detail::BreadthFirstSearch(root, levels);
    return levels;
}

}
