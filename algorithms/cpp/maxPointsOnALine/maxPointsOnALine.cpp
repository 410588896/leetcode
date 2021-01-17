/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

/***********************************
* 
* Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
* 
* Example 1:
* 
* Input: [[1,1],[2,2],[3,3]]
* Output: 3
* Explanation:
* ^
* |
* |        o
* |     o
* |  o  
* +------------->
* 0  1  2  3  4
* Example 2:
* 
* Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
* Output: 4
* Explanation:
* ^
* |
* |  o
* |     o        o
* |        o
* |  o        o
* +------------------->
* 0  1  2  3  4  5  6
* NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
* 
***********************************/

// @lc code=start
class Solution {
    static int gcd(int big, int small) {
        if (big < small)
            swap(big, small);
        
        while (small) {
            int tmp = big % small;
            big = small;
            small = tmp;
        }
        
        return big;
    }

    static pair<int, int> make_grad_pair(int first, int second) {
        if (first == 0 && second == 0)
            return make_pair(0, 0);
        
        if (first < 0) {
            first = -first;
            second = -second;
        }
        
        int i = gcd(first, second);
        return make_pair(first / i, second / i);
    }
    
    struct hash_pair { 
        template <class T1, class T2> 
        size_t operator()(const pair<T1, T2>& p) const { 
            auto hash1 = hash<T1>{}(p.first); 
            auto hash2 = hash<T2>{}(p.second); 
            return hash1 ^ hash2; 
        } 
    };
    
    unordered_map<pair<int, int>, int, hash_pair> lengths;
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3)
            return n;

        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            lengths.clear();
            int x0 = points[i][0], y0 = points[i][1];
            int len = 0, duplicates = 0;
            for (int j = i + 1; j < n; j++) {
                int x1 = points[j][0], y1 = points[j][1];
                if (x0 == x1 && y0 == y1) {
                    duplicates++;
                } else {
                    auto grad = make_grad_pair(x1 - x0, y1 - y0);
                    len = max(len, ++lengths[grad]);
                }
            }
            res = max(res, len + duplicates + 1);
        }
        
        return res;
    }
};
// @lc code=end


