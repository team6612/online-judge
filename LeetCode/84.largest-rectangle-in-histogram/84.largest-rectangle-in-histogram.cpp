/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (34.32%)
 * Likes:    3370
 * Dislikes: 78
 * Total Accepted:    250.4K
 * Total Submissions: 728.7K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        int N = heights.size();
        stack<int> st;
        st.push(-1);
        int ma = 0;
        for (int i=0; i<N; ++i) {
            while (st.top() != -1 && heights[i] < heights[st.top()]) {
                int j = st.top(); st.pop();
                ma = max(ma, heights[j] * (i - st.top() - 1));
            }
            st.push(i);
        }
        while (st.top() != -1) {
            int j = st.top(); st.pop();
            ma = max(ma, heights[j] * (N - st.top() - 1));
        }
        return ma;
    }
};
// @lc code=end
