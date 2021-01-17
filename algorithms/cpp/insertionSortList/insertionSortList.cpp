/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *lastSortedNode = head;
        ListNode *cur = head->next;
        while (cur != nullptr) {
            if (lastSortedNode->val <= cur->val) {
                lastSortedNode = lastSortedNode->next;
            } else {
                ListNode *prev = dummyHead;
                while (prev->next->val <= cur->val) {
                    prev = prev->next;
                }
                lastSortedNode->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
            }
            cur = lastSortedNode->next;
        }
        return dummyHead->next;
    }
};
// @lc code=end


