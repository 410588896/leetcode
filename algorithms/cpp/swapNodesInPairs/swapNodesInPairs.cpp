/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

/***************************************************
* 
* Given a linked list, swap every two adjacent nodes and return its head.
* 
* You may not modify the values in the list's nodes. Only nodes itself may be changed.
* 
*  
* 
* Example 1:
* 
* 
* Input: head = [1,2,3,4]
* Output: [2,1,4,3]
* Example 2:
* 
* Input: head = []
* Output: []
* Example 3:
* 
* Input: head = [1]
* Output: [1]
*  
* 
* Constraints:
* 
* The number of nodes in the list is in the range [0, 100].
* 0 <= Node.val <= 100
* 
***************************************************/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummyHead;
        dummyHead.next = head;
        ListNode *tmp = &dummyHead;
        while (tmp->next != nullptr && tmp->next->next != nullptr) {
            ListNode *node1 = tmp->next;
            ListNode *node2 = tmp->next->next;
            tmp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            tmp = node1;
        }
        return dummyHead.next;
    }
};


