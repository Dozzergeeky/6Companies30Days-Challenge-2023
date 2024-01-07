/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 *
 * https://leetcode.com/problems/bulls-and-cows/description/
 *
 * algorithms
 * Medium (49.96%)
 * Likes:    2345
 * Dislikes: 1763
 * Total Accepted:    362.3K
 * Total Submissions: 724.8K
 * Testcase Example:  '"1807"\n"7810"'
 *
 * You are playing the Bulls and Cows game with your friend.
 *
 * You write down a secret number and ask your friend to guess what the number
 * is. When your friend makes a guess, you provide a hint with the following
 * info:
 *
 *
 * The number of "bulls", which are digits in the guess that are in the correct
 * position.
 * The number of "cows", which are digits in the guess that are in your secret
 * number but are located in the wrong position. Specifically, the non-bull
 * digits in the guess that could be rearranged such that they become bulls.
 *
 *
 * Given the secret number secret and your friend's guess guess, return the
 * hint for your friend's guess.
 *
 * The hint should be formatted as "xAyB", where x is the number of bulls and y
 * is the number of cows. Note that both secret and guess may contain duplicate
 * digits.
 *
 *
 * Example 1:
 *
 *
 * Input: secret = "1807", guess = "7810"
 * Output: "1A3B"
 * Explanation: Bulls are connected with a '|' and cows are underlined:
 * "1807"
 * ⁠ |
 * "7810"
 *
 * Example 2:
 *
 *
 * Input: secret = "1123", guess = "0111"
 * Output: "1A1B"
 * Explanation: Bulls are connected with a '|' and cows are underlined:
 * "1123"        "1123"
 * ⁠ |      or     |
 * "0111"        "0111"
 * Note that only one of the two unmatched 1s is counted as a cow since the
 * non-bull digits can only be rearranged to allow one 1 to be a bull.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= secret.length, guess.length <= 1000
 * secret.length == guess.length
 * secret and guess consist of digits only.
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bulls = 0, cows = 0;
        unordered_map<char, int> count;

        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                bulls++;
            }
            else
            {
                if (count[secret[i]]++ < 0) cows++;
                if (count[guess[i]]-- > 0) cows++;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
    // @lc code=end
