/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

/************************************
* 
* Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in any order.
* 
* A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses. 
* 
*  
* 
* Example 1:
* 
* Input: s = "25525511135"
* Output: ["255.255.11.135","255.255.111.35"]
* Example 2:
* 
* Input: s = "0000"
* Output: ["0.0.0.0"]
* Example 3:
* 
* Input: s = "1111"
* Output: ["1.1.1.1"]
* Example 4:
* 
* Input: s = "010010"
* Output: ["0.10.0.10","0.100.1.0"]
* Example 5:
* 
* Input: s = "101023"
* Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
*  
* 
* Constraints:
* 
* 0 <= s.length <= 3000
* s consists of digits only.
* 
************************************/

// @lc code=start
class Solution {
private:
    static constexpr int SEG_COUNT = 4;
    vector<string> res;
    vector<int> segments;
    void dfs(const string &s, int segID, int segStart) {
        if (segID == SEG_COUNT) {
            if (segStart == s.size()) {
                string ipAddr;
                for (int i = 0; i < SEG_COUNT; i++) {
                    ipAddr += to_string(segments[i]);
                    if (i != SEG_COUNT - 1) {
                        ipAddr += '.';
                    }
                }
                res.push_back(ipAddr);
            }
            return;
        }
        if (segStart == s.size()) return;
        if (s[segStart] == '0') {
            segments[segID] = 0;
            dfs(s, segID + 1, segStart + 1);
        }
        int addr = 0;
        for (int segEnd = segStart; segEnd < s.size(); segEnd++) {
            addr = addr * 10 + (s[segEnd] - '0');
            if (addr > 0 && addr <= 0xff) {
                segments[segID] = addr;
                dfs(s, segID + 1, segEnd + 1);
            } else {
                break;
            }
        }
        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        segments.resize(SEG_COUNT);
        dfs(s, 0, 0);
        return res;
    }
};
// @lc code=end


