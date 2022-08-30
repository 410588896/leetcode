/*
 * @lc app=leetcode.cn id=998 lang=cpp
 *
 * [998] 最大二叉树 II
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *parent = nullptr;
        TreeNode *cur = root;
        while (cur) {
            if (val > cur->val) {
                if (parent == nullptr) {
                    return new TreeNode(val, cur, nullptr);
                }
                parent->right = new TreeNode(val, cur, nullptr);
                return root;
            } else {
                parent = cur;
                cur = cur->right;
            }
        }
        parent->right = new TreeNode(val, nullptr, nullptr);
        return root;
    }
};
// @lc code=end


