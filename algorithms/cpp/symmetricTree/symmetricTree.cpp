/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

/************************************
* 
* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
* 
* For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
* 
*     1
*    / \
*   2   2
*  / \ / \
* 3  4 4  3
*  
* 
* But the following [1,2,2,null,3,null,3] is not:
* 
*     1
*    / \
*   2   2
*    \   \
*    3    3
*  
* 
* Follow up: Solve it both recursively and iteratively.
* 
************************************/

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
    bool check(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) return true;
        if (!p || !q) return false;
        return (p->val == q->val) && check(p->left, q->right) && check(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
// @lc code=end


