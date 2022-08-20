/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> st;
        for (int num : nums) {
            TreeNode* node = new TreeNode(num);
            while (!st.empty() && node->val > st.back()->val) {
                node->left = st.back();
                st.pop_back();
            }
            if (!st.empty()) {
                st.back()->right = node;
            }
            st.push_back(node);
        }
        return st.front();
    }
};
// @lc code=end

