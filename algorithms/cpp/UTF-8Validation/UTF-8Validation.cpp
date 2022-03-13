/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 */

// @lc code=start
class Solution {
private:
    static const int MASK1 = 1 << 7;
    static const int MASK2 = (1 << 7) + (1 << 6);
    bool isValid(int num) {
        return (num & MASK2) == MASK1;
    }
    int getBytes(int num) {
        if ((num & MASK1) == 0) return 1;
        int n = 0;
        int mask = MASK1;
        while ((num & mask) != 0) {
            n ++;
            if (n > 4) return -1;
            mask >>= 1;
        }
        return n >= 2 ? n : -1;
    }
public:
    bool validUtf8(vector<int>& data) {
        int m = data.size();
        int idx = 0;
        while (idx < m) {
            int n = getBytes(data[idx]);
            if (n < 0 || n + idx > m) {
                return false;
            }
            for (int i = 1; i < n; i++) {
                if (!isValid(data[idx + i])) return false;
            }
            idx += n;
        }
        return true;
    }
};
