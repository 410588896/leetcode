/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void recursive(Node* root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->val);
        for (auto &child : root->children) {
            recursive(child, res);
        }
        return;
    }
    vector<int> preorder(Node* root) {
        vector<int> res;
        recursive(root, res);
        return res;
    }
};
