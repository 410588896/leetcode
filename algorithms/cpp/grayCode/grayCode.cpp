/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

/***********************************************
* 
* The gray code is a binary numeral system where two successive values differ in only one bit.
* 
* Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
* 
* Example 1:
* 
* Input: 2
* Output: [0,1,3,2]
* Explanation:
* 00 - 0
* 01 - 1
* 11 - 3
* 10 - 2
* 
* For a given n, a gray code sequence may not be uniquely defined.
* For example, [0,2,3,1] is also a valid gray code sequence.
* 
* 00 - 0
* 10 - 2
* 11 - 3
* 01 - 1
* Example 2:
* 
* Input: 0
* Output: [0]
* Explanation: We define the gray code sequence to begin with 0.
*              A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
*              Therefore, for n = 0 the gray code sequence is [0].
* 
***********************************************/

/*
    格雷编码结论：
    设G(n)表示总位数为n的各类编码集合，根据以下策略可以求出G(n+1)
    1. 将G(n)的每个元素前添加0得到G'(n)
    2. 将G'(n)反转得到镜像R(n)，在R(n)中的每个元素前添加1得到R'(n)
    3. 将G'(n)与R'(n)合并得到G(n+1)
*/

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        int head = 1;
        for (int i = 0; i < n; i++) {
            vector<int> tmp = res;
            for ( auto it = tmp.rbegin(); it != tmp.rend(); ++it ) {
                res.push_back(*it + head);
            }
            head <<= 1;
        }
        return res;
    }
};
// @lc code=end


