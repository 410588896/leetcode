/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
public:
    StockSpanner() {
        this->idx = -1;
        this->st.emplace(-1, INT_MAX);
    }
    
    int next(int price) {
        idx++;
        while(price >= st.top().second) {
            st.pop();
        }
        int res = idx - st.top().first;
        st.emplace(idx, price);
        return res;
    }
private: 
    stack<pair<int, int>> st;
    int idx; 
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end


