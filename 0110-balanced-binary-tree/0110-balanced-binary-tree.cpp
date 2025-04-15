/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }

    pair<bool, int> dfs (TreeNode* root) {
        if (!root) return {1,0};
        pair<bool,int> left = dfs(root->left);
        pair<bool,int> right = dfs(root->right);
        bool balanced = (left.first && right.first && abs(left.second - right.second) <= 1) ? 1 : 0;
        return {balanced, 1 + max(left.second, right.second)};
    } 
};