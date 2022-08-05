/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode(val, root, nullptr);
        vector<TreeNode*> curNodes(1, root);
        for (int i = 1; i < depth - 1; i++) {
            vector<TreeNode*> tmp;
            for (auto &node : curNodes) {
                if (node->left) {
                    tmp.push_back(node->left);
                } 
                if (node->right) {
                    tmp.push_back(node->right);
                }
            }
            curNodes = move(tmp);
        }
        for (auto &node : curNodes) {
            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
        }
        return root;
    }
};
// @lc code=end


