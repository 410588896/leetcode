/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

/******************************************
* 
* Given the head of a linked list, rotate the list to the right by k places.
* 
*  
* 
* Example 1:
* 
* 
* Input: head = [1,2,3,4,5], k = 2
* Output: [4,5,1,2,3]
* Example 2:
* 
* 
* Input: head = [0,1,2], k = 4
* Output: [2,0,1]
*  
* 
* Constraints:
* 
* The number of nodes in the list is in the range [0, 500].
* -100 <= Node.val <= 100
* 0 <= k <= 2 * 109
* 
******************************************/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) 
            return head;
        ListNode *oldTail = head;
        int n = 1;
        while (oldTail->next != NULL) {
            oldTail = oldTail->next;
            n++;
        }
        oldTail->next = head;
        ListNode *newTail = head;
        for (int i = 0; i < n - k % n - 1; i++) 
            newTail = newTail->next;
        head = newTail->next;
        newTail->next = NULL;
        return head;
    }
};
// @lc code=end


