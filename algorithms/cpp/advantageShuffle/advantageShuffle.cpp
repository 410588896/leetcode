/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> idx1(n);
        vector<int> idx2(n);
        vector<int> res(n);
        iota(idx1.begin(), idx1.end(), 0);
        iota(idx2.begin(), idx2.end(), 0);
        sort(idx1.begin(), idx1.end(), [&](int i, int j){return nums1[i] < nums1[j];});
        sort(idx2.begin(), idx2.end(), [&](int i, int j){return nums2[i] < nums2[j];});
        int left = 0, right = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums1[idx1[i]] > nums2[idx2[left]]) {
                res[idx2[left]] = nums1[idx1[i]];
                left++;
            } else {
                res[idx2[right]] = nums1[idx1[i]];
                right--;
            }
        }
        return res;
    }
};
// @lc code=end


