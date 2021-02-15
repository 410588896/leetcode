/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 */

/************************************
* 
* You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
* 
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.
* 
* Follow up:
* What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
* 
* Example:
* 
* Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 8 -> 0 -> 7
* 
************************************/

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> l1Stack;
        stack<int> l2Stack;
        while (l1) {
            l1Stack.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            l2Stack.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode *next = nullptr;
        while (l1Stack.size() != 0 || l2Stack.size() != 0 || carry) {
            int a = l1Stack.empty() ? 0 : l1Stack.top();
            int b = l2Stack.empty() ? 0 : l2Stack.top();
            if (!l1Stack.empty()) l1Stack.pop();
            if (!l2Stack.empty()) l2Stack.pop();
            int val = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            ListNode *cur = new ListNode(val, next);
            next = cur;
        }
        return next;
    }
};
// @lc code=end


