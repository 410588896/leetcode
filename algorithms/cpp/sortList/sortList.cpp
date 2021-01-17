/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

/************************************
* 
* Given the head of a linked list, return the list after sorting it in ascending order.
* 
* Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
* 
*  
* 
* Example 1:
* 
* 
* Input: head = [4,2,1,3]
* Output: [1,2,3,4]
* Example 2:
* 
* 
* Input: head = [-1,5,3,4,0]
* Output: [-1,0,3,4,5]
* Example 3:
* 
* Input: head = []
* Output: []
*  
* 
* Constraints:
* 
* The number of nodes in the list is in the range [0, 5 * 104].
* -105 <= Node.val <= 105
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
private:
    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *tmp = dummyHead;
        ListNode *tmp1 = head1, *tmp2 = head2;
        while (tmp1 != nullptr && tmp2 != nullptr) {
            if (tmp1->val <= tmp2->val) {
                tmp->next = tmp1;
                tmp1 = tmp1->next;
            } else {
                tmp->next = tmp2;
                tmp2 = tmp2->next;
            }
            tmp = tmp->next;
        }
        if (tmp1 != nullptr) {
            tmp->next = tmp1;
        } else if (tmp2 != nullptr) {
            tmp->next = tmp2;
        }
        return dummyHead->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return head;
        int length = 0;
        ListNode *node = head;
        while (node != nullptr) {
            node = node->next;
            length++;
        }
        ListNode *dummyHead = new ListNode(-1, head);
        for (int i = 0; i < length; i <<= 1) {
            ListNode *prev = dummyHead, *cur = dummyHead->next;
            while (cur != nullptr) {
                ListNode *head1 = cur;
                for (int j = 1; j < i && cur->next != nullptr; j++) {
                    cur = cur->next;
                }
                ListNode *head2 = cur->next;
                cur->next = nullptr;
                cur = head2;
                for (int j = 0; j < i && cur != nullptr && cur->next != nullptr; i++) {
                    cur = cur->next;
                }
            }
        }
    }
};
// @lc code=end


