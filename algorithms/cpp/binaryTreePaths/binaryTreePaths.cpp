/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void dfs(TreeNode* node, string path, vector<string> &res) {
        if (!node->left && !node->right) {
            if (path == "") res.push_back(to_string(node->val));
            else res.push_back(path + "->" + to_string(node->val));
        }
        if (path == "") path += to_string(node->val);
        else path += "->" + to_string(node->val);
        if (node->left) {
            dfs(node->left, path, res);
        } 
        if (node->right) {
            dfs(node->right, path, res);
        }
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
};
// @lc code=end


