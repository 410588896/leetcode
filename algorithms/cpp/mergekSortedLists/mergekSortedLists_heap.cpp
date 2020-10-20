/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

/***************************************************
* 
*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
*
*Merge all the linked-lists into one sorted linked-list and return it.
*
* 
*
*Example 1:
*
*Input: lists = [[1,4,5],[1,3,4],[2,6]]
*Output: [1,1,2,3,4,4,5,6]
*Explanation: The linked-lists are:
*[
*  1->4->5,
*  1->3->4,
*  2->6
*]
*merging them into one sorted list:
*1->1->2->3->4->4->5->6
*Example 2:
*
*Input: lists = []
*Output: []
*Example 3:
*
*Input: lists = [[]]
*Output: []
* 
*
*Constraints:
*
*k == lists.length
*0 <= k <= 10^4
*0 <= lists[i].length <= 500
*-10^4 <= lists[i][j] <= 10^4
*lists[i] is sorted in ascending order.
*The sum of lists[i].length won't exceed 10^4.
*
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
private:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &b) const {
            return val > b.val;
        }
    };

    priority_queue<Status> q;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto item : lists) {
            if (item) q.push({item->val, item});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto node = q.top(); q.pop();
            tail->next = node.ptr;
            tail = tail->next;
            if (node.ptr->next) q.push({node.ptr->next->val, node.ptr->next});
        }
        return head.next;
    }
};


