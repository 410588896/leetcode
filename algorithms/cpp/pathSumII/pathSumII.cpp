/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 */

/*********************************
* 
* Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
* 
* Note: A leaf is a node with no children.
* 
* Example:
* 
* Given the below binary tree and sum = 22,
* 
*       5
*      / \
*     4   8
*    /   / \
*   11  13  4
*  /  \    / \
* 7    2  5   1
* Return:
* 
* [
*    [5,4,11,2],
*    [5,8,4,5]
* ]
* 
*********************************/

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
    vector<vector<int> > res;
    vector<int> path;
    void dfs(TreeNode *root, int sum) {
        if (root == nullptr) return;
        path.push_back(root->val);
        if (sum == root->val && root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
            path.pop_back();
            return;
        }
        sum -= root->val;
        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back();
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return res;
    }
};
// @lc code=end


