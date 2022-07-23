/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {

    }
    
    void push(int x) {
        while (s2.size()) {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
        while (s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    int pop() {
        int res = s2.top();
        s2.pop();
        return res;
    }
    
    int peek() {
        return s2.top();
    }
    
    bool empty() {
        return s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end


