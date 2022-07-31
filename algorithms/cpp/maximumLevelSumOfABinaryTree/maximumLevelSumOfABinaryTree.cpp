/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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
    int maxLevelSum(TreeNode* root) {
        int res = 1, maxSum = root->val;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int currentLevelLen = 1;
        while (!q.empty()) {
            int sum = 0;
            int nextLevelLen = 0;
            for (int i = 0; i < currentLevelLen; i++) {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                    nextLevelLen += 1;
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                    nextLevelLen += 1;
                }
            } 
            level++;
            currentLevelLen = nextLevelLen;
            if (sum > maxSum) {
                res = level;
                maxSum = sum;
            }
        }
        return res;
    }
};
// @lc code=end


