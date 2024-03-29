/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
class MyCircularQueue {
private:
    int front;
    int rear;
    int capacity;
    vector<int> elements;
public:
    MyCircularQueue(int k) {
        capacity = k + 1;
        front = 0;
        rear = 0;
        elements = vector<int>(capacity);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        elements[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return elements[front];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return elements[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end


