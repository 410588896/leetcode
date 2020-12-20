/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

/*************************
* 
* Given inorder and postorder traversal of a tree, construct the binary tree.
* 
* Note:
* You may assume that duplicates do not exist in the tree.
* 
* For example, given
* 
* inorder = [9,3,15,20,7]
* postorder = [9,15,7,20,3]
* Return the following binary tree:
* 
*     3
*    / \
*   9  20
*     /  \
*    15   7
* 
*************************/

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
    int postIdx;
    unordered_map<int, int> index;
    TreeNode* myConstruct(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;
        TreeNode *root = new TreeNode(postorder[postIdx]);
        int idx = index[postorder[postIdx]];
        postIdx--;
        root->right = myConstruct(inorder, postorder, idx + 1, inRight);
        root->left = myConstruct(inorder, postorder, inLeft, idx - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIdx = n - 1;
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return myConstruct(inorder, postorder, 0, n - 1);
    }
};
// @lc code=end


