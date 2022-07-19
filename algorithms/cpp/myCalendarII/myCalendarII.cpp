/*
 * @lc app=leetcode.cn id=731 lang=cpp
 *
 * [731] 我的日程安排表 II
 */

// @lc code=start
class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        cnt[start] ++;
        cnt[end] --;
        int maxBook = 0;
        for (auto &[_, freq] : cnt) {
            maxBook += freq;
            if (maxBook > 2) {
                cnt[start] --;
                cnt[end] ++;
                return false;
            } 
        }
        return true;
    }
private:
    map<int, int> cnt;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end


