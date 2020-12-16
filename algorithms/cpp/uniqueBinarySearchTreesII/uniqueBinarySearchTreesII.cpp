/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

/**************************************
* 
* Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
* 
* Example:
* 
* Input: 3
* Output:
* [
*   [1,null,3,2],
*   [3,2,null,1],
*   [3,1,null,null,2],
*   [2,1,3],
*   [1,null,2,null,3]
* ]
* Explanation:
* The above output corresponds to the 5 unique BST's shown below:
* 
*    1         3     3      2      1
*     \       /     /      / \      \
*      3     2     1      1   3      2
*     /     /       \                 \
*    2     1         2                 3
*  
* 
* Constraints:
* 
* 0 <= n <= 8
* 
**************************************/

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
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) return {nullptr};
        vector<TreeNode*> res;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);
            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* cur = new TreeNode(i, left, right);
                    res.push_back(cur);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return {};
        return generateTrees(1, n);
    }
};
// @lc code=end


