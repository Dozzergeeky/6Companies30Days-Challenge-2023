/*
 * @lc app=leetcode id=2099 lang=cpp
 *
 * [2099] Find Subsequence of Length K With the Largest Sum
 *
 * https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/
 *
 * algorithms
 * Easy (42.93%)
 * Likes:    1170
 * Dislikes: 114
 * Total Accepted:    43.4K
 * Total Submissions: 101K
 * Testcase Example:  '[2,1,3,3]\n2'
 *
 * You are given an integer array nums and an integer k. You want to find a
 * subsequence of nums of length k that has the largest sum.
 *
 * Return any such subsequence as an integer array of length k.
 *
 * A subsequence is an array that can be derived from another array by deleting
 * some or no elements without changing the order of the remaining elements.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,1,3,3], k = 2
 * Output: [3,3]
 * Explanation:
 * The subsequence has the largest sum of 3 + 3 = 6.
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,-2,3,4], k = 3
 * Output: [-1,3,4]
 * Explanation:
 * The subsequence has the largest sum of -1 + 3 + 4 = 6.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,4,3,3], k = 2
 * Output: [3,4]
 * Explanation:
 * The subsequence has the largest sum of 3 + 4 = 7.
 * Another possible subsequence is [4, 3].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * -10^5 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
 *
 *
 */

// @lc code=start
class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) 
    { 
        return a.second < b.second; 
    } 

    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        if (nums.size() == k)
            return nums;

        vector<pair<int, int>> temp;

        for (int i = 0; i < nums.size(); i++)
            temp.push_back(make_pair(nums[i], i));
            
        vector<int> ans;

        sort(temp.begin(), temp.end());

        temp.erase(temp.begin(), temp.end() - k);

        sort(temp.begin(), temp.end(), cmp);

        for(int i = 0; i < temp.size(); i++)
            ans.push_back(temp[i].first);

        return ans;
    }
};
// @lc code=end
