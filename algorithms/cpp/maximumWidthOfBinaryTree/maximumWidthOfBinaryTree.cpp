/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long res = 0;
        vector<pair<TreeNode*, unsigned long long>> arr;
        arr.push_back(make_pair(root, 1L));
        while (!arr.empty()) {
            vector<pair<TreeNode*, unsigned long long>> tmp;
            for (auto &[node, index] : arr) {
                if (node->left) {
                    tmp.push_back(make_pair(node->left, index * 2));
                }
                if (node->right) {
                    tmp.push_back(make_pair(node->right, index * 2 + 1));
                }
            } 
            res = max(res, arr.back().second - arr[0].second + 1);
            arr = move(tmp);
        }
        return res;
    }
};
// @lc code=end


