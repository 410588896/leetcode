/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 */

/***********************************************
* 
* Given a binary tree, flatten it to a linked list in-place.
* 
* For example, given the following tree:
* 
*     1
*    / \
*   2   5
*  / \   \
* 3   4   6
* The flattened tree should look like:
* 
* 1
*  \
*   2
*    \
*     3
*      \
*       4
*        \
*         5
*          \
*           6
* 
***********************************************/

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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        auto stk = stack<TreeNode*>();
        stk.push(root);
        TreeNode *prev = nullptr;
        while (!stk.empty()) {
            TreeNode* cur = stk.top(); stk.pop();
            if (prev != nullptr) {
                prev->left = nullptr;
                prev->right = cur;
            }
            TreeNode *right = cur->right, *left = cur->left;
            if (right != nullptr)
                stk.push(right);
            if (left != nullptr)
                stk.push(left);
            prev = cur;
        }
    }
};
// @lc code=end


