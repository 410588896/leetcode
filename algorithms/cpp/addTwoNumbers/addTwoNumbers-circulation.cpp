/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

/************************************************************************************************
*
* You are given two non-empty linked lists representing two non-negative integers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
*
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*
* Example:
*
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
* Explanation: 342 + 465 = 807.
*
*
************************************************************************************************/

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
        ListNode *newHead = new ListNode(0);
        ListNode *p = l1, *q = l2, *curr = newHead;
        int mantissa = 0;
        while(p != NULL || q != NULL) {
            int x = (p != NULL) ? p->val : 0;
            int y = (q != NULL) ? q->val : 0;
            int sum = (x + y + mantissa) % 10;
            mantissa = (x + y + mantissa) / 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            if (p != NULL) p = p->next;
            if (q != NULL) q = q->next;
        }
        if (mantissa > 0) {
            curr->next = new ListNode(mantissa);
        }
        return newHead->next;
    }
};
// @lc code=end
