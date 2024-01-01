/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (59.39%)
 * Likes:    17734
 * Dislikes: 932
 * Total Accepted:    1.9M
 * Total Submissions: 3.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 * 
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = ""
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 * 
 * 
 */

// @lc code=start
class Solution {
private:
    void solve(string digits, string output, int index, string mapping[], vector<string> &ans) {
        //base case
        if(index >= digits.size()) {
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string value = mapping[number];

        for(int i = 0; i < value.size(); i++) {
            output.push_back(value[i]);
            solve(digits, output, index+1, mapping, ans);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) {
            return ans;
        }
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", 
            "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, mapping, ans);
        return ans;
        
};
};
// @lc code=end

