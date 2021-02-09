/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 */

/***************************************
* 
* Given the root of a complete binary tree, return the number of the nodes in the tree.
* 
* According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
* 
*  
* 
* Example 1:
* 
* 
* Input: root = [1,2,3,4,5,6]
* Output: 6
* Example 2:
* 
* Input: root = []
* Output: 0
* Example 3:
* 
* Input: root = [1]
* Output: 1
*  
* 
* Constraints:
* 
* The number of nodes in the tree is in the range [0, 5 * 104].
* 0 <= Node.val <= 5 * 104
* The tree is guaranteed to be complete.
*  
* 
* Follow up: Traversing the tree to count the number of nodes in the tree is an easy solution but with O(n) complexity. Could you find a faster algorithm?
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
private:
    bool exists(TreeNode *root, int level, int k) {
        int bits = 1 << (level - 1);
        TreeNode *node = root;
        while (node != nullptr && bits > 0) {
            if (!(bits & k)) {
                node = node->left;
            } else {
                node = node->right;
            }
            bits >>= 1;
        }
        return node != nullptr;
    }
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int level = 0;
        TreeNode *node = root;
        while (node->left != nullptr) {
            node = node->left;
            level += 1;
        }        
        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, level, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
// @lc code=end


