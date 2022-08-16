/*
 * @lc app=leetcode.cn id=1656 lang=cpp
 *
 * [1656] 设计有序流
 */

// @lc code=start
class OrderedStream {
private:
    vector<string> elements;
    int ptr;
public:
    OrderedStream(int n) {
        elements.resize(n + 1);
        ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        elements[idKey] = value;
        vector<string> res;
        while(ptr < elements.size() && !elements[ptr].empty()) {
            res.push_back(elements[ptr++]);
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end


