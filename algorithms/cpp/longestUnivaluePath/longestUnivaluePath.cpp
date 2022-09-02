/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 */

// @lc code=start
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
private:
    int res;
    int dfs(TreeNode *node) {
        if (node == nullptr) return 0;
        int left1 = 0, right1 = 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        if (node->left != nullptr && node->left->val == node->val) {
            left1 = left + 1;
        }
        if (node->right != nullptr && node->right->val == node->val) {
            right1 = right + 1;
        }
        res = max(res, left1 + right1);
        return max(left1, right1);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;   
    }
};
// @lc code=end


