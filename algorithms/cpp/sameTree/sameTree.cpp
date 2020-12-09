/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */

/***************************************
* 
* Given two binary trees, write a function to check if they are the same or not.
* 
* Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
* 
* Example 1:
* 
* Input:     1         1
*           / \       / \
*          2   3     2   3
* 
*         [1,2,3],   [1,2,3]
* 
* Output: true
* Example 2:
* 
* Input:     1         1
*           /           \
*          2             2
* 
*         [1,2],     [1,null,2]
* 
* Output: false
* Example 3:
* 
* Input:     1         1
*           / \       / \
*          2   1     1   2
* 
*         [1,2,1],   [1,1,2]
* 
* Output: false
* 
***************************************/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        else if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;
        else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};
// @lc code=end


