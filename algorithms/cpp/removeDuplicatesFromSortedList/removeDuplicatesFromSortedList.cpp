/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

/*********************************************
* 
* Given a sorted linked list, delete all duplicates such that each element appear only once.
* 
* Example 1:
* 
* Input: 1->1->2
* Output: 1->2
* Example 2:
* 
* Input: 1->1->2->3->3
* Output: 1->2->3
* 
*********************************************/

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
        if (head == nullptr) return head;
        ListNode *tmp = head;
        while (tmp != nullptr && tmp->next != nullptr) {
            if (tmp->val == tmp->next->val) {
                tmp->next = tmp->next->next;
            } else {
                tmp = tmp->next;
            }
        }
        return head;
    }
};
// @lc code=end


