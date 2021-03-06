/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

/***********************************************
* 
* Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
* 
* You should preserve the original relative order of the nodes in each of the two partitions.
* 
* Example:
* 
* Input: head = 1->4->3->2->5->2, x = 3
* Output: 1->2->2->4->3->5
* 
***********************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head;
        ListNode *before = new ListNode(-1, NULL);
        ListNode *after = new ListNode(-1, NULL);
        ListNode *beforeTmp = before;
        ListNode *afterTmp = after;
        while (head != NULL) {
            if (head->val < x) {
                beforeTmp->next = head;
                beforeTmp = beforeTmp->next;
            } else {
                afterTmp->next = head;
                afterTmp = afterTmp->next;
            }
            head = head->next;
        }
        afterTmp->next = NULL;
        beforeTmp->next = after->next;
        return before->next;
    }
};


