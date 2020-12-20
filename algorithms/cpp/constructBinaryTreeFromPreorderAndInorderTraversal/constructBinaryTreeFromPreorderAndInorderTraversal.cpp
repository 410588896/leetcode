/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

/***********************************
* 
* Given preorder and inorder traversal of a tree, construct the binary tree.
* 
* Note:
* You may assume that duplicates do not exist in the tree.
* 
* For example, given
* 
* preorder = [3,9,20,15,7]
* inorder = [9,3,15,20,7]
* Return the following binary tree:
* 
*     3
*    / \
*   9  20
*     /  \
*    15   7
* 
***********************************/

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
    unordered_map<int, int> index;
    TreeNode* myConstruct(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight) {
        if (preLeft > preRight) return nullptr;
        int preRoot = preLeft;
        TreeNode *root = new TreeNode(preorder[preRoot]);
        int size = index[preorder[preRoot]] - inLeft;
        root->left = myConstruct(preorder, inorder, preLeft + 1, preLeft + size, inLeft, index[preorder[preRoot]] - 1);
        root->right = myConstruct(preorder, inorder, preLeft + size + 1, preRight, index[preorder[preRoot]] + 1, inRight);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return myConstruct(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
// @lc code=end


