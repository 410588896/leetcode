/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

/***********************************
* 
* Given a singly linked list L: L0→L1→…→Ln-1→Ln,
* reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
* 
* You may not modify the values in the list's nodes, only nodes itself may be changed.
* 
* Example 1:
* 
* Given 1->2->3->4, reorder it to 1->4->2->3.
* Example 2:
* 
* Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
* 
***********************************/

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
    void merge(ListNode *l1, ListNode *l2) {
        ListNode *l1Tmp = nullptr, *l2Tmp = nullptr;
        while (l1 != nullptr && l2 != nullptr) {
            l1Tmp = l1->next;
            l2Tmp = l2->next;
            l1->next = l2;
            l1 = l1Tmp;
            l2->next = l1;
            l2 = l2Tmp;
        }
        return;
    }
    ListNode *findMid(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *nextTmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextTmp;
        }
        return pre;
    }
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        ListNode *mid = findMid(head);
        ListNode *l1 = head;
        ListNode *l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        merge(l1, l2);
        return;
    }
};
// @lc code=end


