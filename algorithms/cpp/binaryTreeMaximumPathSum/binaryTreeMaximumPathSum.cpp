/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

/************************************************
* 
* Given a non-empty binary tree, find the maximum path sum.
* 
* For this problem, a path is defined as any node sequence from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
* 
*  
* 
* Example 1:
* 
* 
* Input: root = [1,2,3]
* Output: 6
* Example 2:
* 
* 
* Input: root = [-10,9,20,null,null,15,7]
* Output: 42
*  
* 
* Constraints:
* 
* The number of nodes in the tree is in the range [0, 3 * 104].
* -1000 <= Node.val <= 1000
* 
************************************************/

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
    int maxGainSum = INT_MIN;
    int maxGain(TreeNode *node) {
        if (node == nullptr) return 0;
        int leftGain =  max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);
        maxGainSum = max(maxGainSum, node->val + leftGain + rightGain);
        return node->val + max(leftGain, rightGain);
    }
public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxGainSum;

    }
};
// @lc code=end


