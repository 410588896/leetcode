/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

/***************************************
* 
* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
* 
* push(x) -- Push element x onto stack.
* pop() -- Removes the element on top of the stack.
* top() -- Get the top element.
* getMin() -- Retrieve the minimum element in the stack.
*  
* 
* Example 1:
* 
* Input
* ["MinStack","push","push","push","getMin","pop","top","getMin"]
* [[],[-2],[0],[-3],[],[],[],[]]
* 
* Output
* [null,null,null,null,-3,null,0,-2]
* 
* Explanation
* MinStack minStack = new MinStack();
* minStack.push(-2);
* minStack.push(0);
* minStack.push(-3);
* minStack.getMin(); // return -3
* minStack.pop();
* minStack.top();    // return 0
* minStack.getMin(); // return -2
*  
* 
* Constraints:
* 
* Methods pop, top and getMin operations will always be called on non-empty stacks.
* 
***************************************/

// @lc code=start
class MinStack {
private:
    stack<int> minStack;
    stack<int> storeStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        minStack.push(INT_MAX);
        return;
    }
    
    void push(int x) {
        minStack.push(min(minStack.top(), x));
        storeStack.push(x);
        return;
    }

    void pop() {
        minStack.pop();
        storeStack.pop();
        return;
    }
    
    int top() {
        return storeStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end


