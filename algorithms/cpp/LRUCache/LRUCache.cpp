/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

/**********************************
* 
* Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
* 
* Implement the LRUCache class:
* 
* LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
* int get(int key) Return the value of the key if the key exists, otherwise return -1.
* void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
* Follow up:
* Could you do get and put in O(1) time complexity?
* 
*  
* 
* Example 1:
* 
* Input
* ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
* [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
* Output
* [null, null, null, 1, null, -1, null, -1, 3, 4]
* 
* Explanation
* LRUCache lRUCache = new LRUCache(2);
* lRUCache.put(1, 1); // cache is {1=1}
* lRUCache.put(2, 2); // cache is {1=1, 2=2}
* lRUCache.get(1);    // return 1
* lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
* lRUCache.get(2);    // returns -1 (not found)
* lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
* lRUCache.get(1);    // return -1 (not found)
* lRUCache.get(3);    // return 3
* lRUCache.get(4);    // return 4
*  
* 
* Constraints:
* 
* 1 <= capacity <= 3000
* 0 <= key <= 3000
* 0 <= value <= 104
* At most 3 * 104 calls will be made to get and put.
* 
**********************************/

// @lc code=start
struct DlinkedNode {
    int key, value;
    DlinkedNode *prev;
    DlinkedNode *next;
    DlinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DlinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}   
};

class LRUCache {
private:
    unordered_map<int, DlinkedNode*> cache;
    DlinkedNode *head;
    DlinkedNode *tail;
    int size;
    int capacity;

    void addToHead(DlinkedNode *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        return;
    }

    void moveToHead(DlinkedNode *node) {
        removeNode(node);
        addToHead(node);
        return;
    }

    void removeNode(DlinkedNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    DlinkedNode *removeTail() {
        DlinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new DlinkedNode();
        tail = new DlinkedNode();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    int get(int key) {
        if (cache.count(key) == 0) return -1;
        DlinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.count(key) == 0) {
            DlinkedNode *node = new DlinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity) {
                DlinkedNode *removeNode = removeTail();
                cache.erase(removeNode->key);
                delete removeNode;
                --size;
            }
        } else {
            DlinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


