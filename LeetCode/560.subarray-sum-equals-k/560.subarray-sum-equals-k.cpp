/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.80%)
 * Likes:    4454
 * Dislikes: 142
 * Total Accepted:    304.3K
 * Total Submissions: 694.5K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * 
 * 
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        unordered_map<int, int> M;
        int sum = 0, ans = 0;
        M[sum] = 1;
        for (int i=0; i<N; ++i) {
            sum += nums[i];
            if (M.count(sum - k)) {
                ans += M[sum - k];
            }
            M[sum] = M.count(sum) ? M[sum] + 1 : 1;
        }
        return ans;
    }
};
// @lc code=end
