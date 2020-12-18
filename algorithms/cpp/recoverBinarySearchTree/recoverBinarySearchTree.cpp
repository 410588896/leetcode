/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 */

/*************************************
* 
* You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
* 
* Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
* 
*  
* 
* Example 1:
* 
* 
* Input: root = [1,3,null,null,2]
* Output: [3,1,null,null,2]
* Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
* Example 2:
* 
* 
* Input: root = [3,1,4,null,null,2]
* Output: [2,1,4,null,null,3]
* Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
*  
* 
* Constraints:
* 
* The number of nodes in the tree is in the range [2, 1000].
* -231 <= Node.val <= 231 - 1
* 
*************************************/

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
    void inorder(TreeNode* root, vector<int> &nums) {
        if (root == nullptr) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
        return;
    }
    pair<int, int> locateInverse(vector<int> &nums) {
        int x = -1, y = -1;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] < nums[i]) {
                y = nums[i + 1];
                if (x == -1) {
                    x = nums[i];
                } else break;
            }
        }
        return {x, y};
    }
    void recover(TreeNode *root, int count, int x, int y) {
        if (root != nullptr) {
            if (root->val == x || root->val == y) {
                root->val = root->val == x ? y : x;
                if (--count == 0) return;
            }
            recover(root->left, count, x, y);
            recover(root->right, count, x, y);
        }
        return;
    } 
public:
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        pair<int, int> swapped = locateInverse(nums);
        recover(root, 2, swapped.first, swapped.second);
        return;
    }
};
// @lc code=end


