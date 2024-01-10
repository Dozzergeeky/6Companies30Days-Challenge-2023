/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (48.18%)
 * Likes:    3211
 * Dislikes: 513
 * Total Accepted:    357.6K
 * Total Submissions: 741K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * The DNA sequence is composed of a series of nucleotides abbreviated as 'A',
 * 'C', 'G', and 'T'.
 * 
 * 
 * For example, "ACGAATTCCG" is a DNA sequence.
 * 
 * 
 * When studying DNA, it is useful to identify repeated sequences within the
 * DNA.
 * 
 * Given a string s that represents a DNA sequence, return all the
 * 10-letter-long sequences (substrings) that occur more than once in a DNA
 * molecule. You may return the answer in any order.
 * 
 * 
 * Example 1:
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * Output: ["AAAAACCCCC","CCCCCAAAAA"]
 * Example 2:
 * Input: s = "AAAAAAAAAAAAA"
 * Output: ["AAAAAAAAAA"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] is either 'A', 'C', 'G', or 'T'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        unordered_set<string> seen;
        unordered_set<string> temp;

        int n = s.length();

        for(int i = 0; i < n - 9; i++)
        {
            string dna = s.substr(i, 10);
            
            if(seen.find(dna) != seen.end())
                temp.insert(dna);
            else
                seen.insert(dna);
        }

        vector<string> ans(temp.begin(), temp.end());
        
        return ans;
    }
};
// @lc code=end

