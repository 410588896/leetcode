/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

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
