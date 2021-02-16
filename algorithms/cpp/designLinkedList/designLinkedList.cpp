/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

/**********************************
* 
* Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
* A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
* If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.
* 
* Implement the MyLinkedList class:
* 
* MyLinkedList() Initializes the MyLinkedList object.
* int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
* void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
* void addAtTail(int val) Append a node of value val as the last element of the linked list.
* void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
* void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
*  
* 
* Example 1:
* 
* Input
* ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
* [[], [1], [3], [1, 2], [1], [1], [1]]
* Output
* [null, null, null, null, 2, null, 3]
* 
* Explanation
* MyLinkedList myLinkedList = new MyLinkedList();
* myLinkedList.addAtHead(1);
* myLinkedList.addAtTail(3);
* myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
* myLinkedList.get(1);              // return 2
* myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
* myLinkedList.get(1);              // return 3
*  
* 
* Constraints:
* 
* 0 <= index, val <= 1000
* Please do not use the built-in LinkedList library.
* At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex and deleteAtIndex.
* 
**********************************/

// @lc code=start
class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next, *prev;
        ListNode(int x):val(x), next(nullptr), prev(nullptr){}
    };
    ListNode *head, *tail;
    int size = 0;
public:
    /** Initialize your data structure here. */
    MyLinkedList() : size(0) {
        head = new ListNode(-1);
        tail = new ListNode(-1);
        head->next = tail;
        tail->prev = head;
        head->prev = nullptr;
        tail->next = nullptr;
        return;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index > size - 1) return -1;
        ListNode *p = head;
        for (int i = 0; i <= index; i++) {
            p = p->next;
        }
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *p = new ListNode(val);
        p->next = head->next;
        head->next->prev = p;
        p->prev = head;
        head->next = p;
        size++;
        return;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *p = new ListNode(val);
        tail->prev->next = p;
        p->prev = tail->prev;
        p->next = tail;
        tail->prev = p;  
        size++;   
        return;  
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) {
            addAtHead(val); 
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        ListNode *p = head;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        ListNode *node = new ListNode(val);
        node->next = p->next;
        p->next->prev = node;
        node->prev = p;
        p->next = node;
        size++;
        return;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (size == 0) return;
        if (size - 1 < index) return;
        if (index < 0) return;
        ListNode *p = head;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        ListNode *deleteNode = p->next;
        p->next = deleteNode->next;
        deleteNode->next->prev = p;
        delete deleteNode;
        --size;
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end


