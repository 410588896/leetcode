/*
 * @lc app=leetcode.cn id=768 lang=cpp
 *
 * [768] 最多能完成排序的块 II
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for (auto elem : arr) {
            if (st.empty() || st.top() <= elem) {
                st.push(elem);
            } else {
                int maxElem = st.top();
                st.pop();
                while (!st.empty() && st.top() > elem) {
                    st.pop();
                }
                st.push(maxElem);
            }
        }
        return st.size();
    }
};
// @lc code=end


