/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        ListNode *node = head;
        while (node != nullptr) {
            vals.push_back(node->val);
            node = node->next;
        }
        int left = 0, right = vals.size() - 1;
        while (left <= right) {
            if (vals[left] != vals[right]) return false;
            left++, right--;
        }
        return true;
    }
};
// @lc code=end


