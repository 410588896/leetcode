/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

/********************************************************
* 
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
* 
* k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
* 
* Follow up:
* 
* Could you solve the problem in O(1) extra memory space?
* You may not alter the values in the list's nodes, only nodes itself may be changed.
*  
* 
* Example 1:
* 
* 
* Input: head = [1,2,3,4,5], k = 2
* Output: [2,1,4,3,5]
* Example 2:
* 
* 
* Input: head = [1,2,3,4,5], k = 3
* Output: [3,2,1,4,5]
* Example 3:
* 
* Input: head = [1,2,3,4,5], k = 1
* Output: [1,2,3,4,5]
* Example 4:
* 
* Input: head = [1], k = 1
* Output: [1]
*  
* 
* Constraints:
* 
* The number of nodes in the list is in the range sz.
* 1 <= sz <= 5000
* 0 <= Node.val <= 1000
* 1 <= k <= sz
* 
*******************************************************/

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
private:
    pair<ListNode*, ListNode*> reverseOne(ListNode* head, ListNode* tail) {
        ListNode *prev = tail->next;
        ListNode *p = head;
        while (prev != tail) {
            ListNode *next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return {tail, head};
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *pre = dummyHead;
        while (head) {
            ListNode *tail = pre;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    return dummyHead->next;
                }
            }
            ListNode* next = tail->next;
            tie(head, tail) = reverseOne(head, tail);
            tail->next = next;
            pre->next = head;
            pre = tail;
            head = tail->next;
        }
        return dummyHead->next;
    }
};
// @lc code=end


