/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */

/***********************************************
* 
* Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
* 
* Return the linked list sorted as well.
* 
* Example 1:
* 
* Input: 1->2->3->3->4->4->5
* Output: 1->2->5
* Example 2:
* 
* Input: 1->1->1->2->3
* Output: 2->3
* 
***********************************************/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode *dummy = new ListNode(-1, head);
        ListNode *a = dummy;
        ListNode *b = head;
        while (b != nullptr && b->next != nullptr) {
            if (a->next->val != b->next->val) {
                a = a->next, b = b->next;
            } else {
                while (b != nullptr && b->next != nullptr && a->next->val == b->next->val) {
                    b = b->next;
                }
                a->next = b->next;
                b = b->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end


