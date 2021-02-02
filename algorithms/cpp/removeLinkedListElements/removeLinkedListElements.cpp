/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 */

/*****************************************

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

*****************************************/

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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *pre = dummyHead, *cur = head;
        while (cur != nullptr) {
            if (cur->val == val) {
                pre->next = cur->next;
            } else pre->next = cur;
            cur = cur->next;
        }
        return dummyHead->next;
    }
};
// @lc code=end


