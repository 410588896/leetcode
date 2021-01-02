/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

/******************************************
* 
* Given a binary tree
* 
* struct Node {
*   int val;
*   Node *left;
*   Node *right;
*   Node *next;
* }
* Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
* 
* Initially, all next pointers are set to NULL.
* 
*  
* 
* Follow up:
* 
* You may only use constant extra space.
* Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
*  
* 
* Example 1:
* 
* 
* 
* Input: root = [1,2,3,4,5,null,7]
* Output: [1,#,2,3,#,4,5,7,#]
* Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
*  
* 
* Constraints:
* 
* The number of nodes in the given tree is less than 6000.
* -100 <= node.val <= 100
* 
******************************************/

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void findNext(Node* &last, Node* &p, Node* &nextStart) {
        if (last) last->next = p;
        if (nextStart == nullptr) nextStart = p;
        last = p;
    }
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        Node *start = root;
        while(start) {
            Node* last = nullptr;
            Node* nextStart = nullptr;
            for (Node *p = start; p != nullptr; p = p->next) {
                if (p->left)
                    findNext(last, p->left, nextStart);
                if (p->right)
                    findNext(last, p->right, nextStart);
            }
            start = nextStart;
        }
        return root;
    }
};
// @lc code=end


