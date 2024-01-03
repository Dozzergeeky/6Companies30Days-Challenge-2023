// Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. Digits from 1-9 and digits can't repeat.

// Example 1:

// Input:
// D
// Output:
// 21
// Explanation:
// D is meant for decreasing, so we choose the minimum number among all possible numbers like 21,31,54,87,etc.
// Example 2:

// Input:
// IIDDD
// Output:
// 126543
// Explanation:
// Above example is self- explanatory,
// 1 < 2 < 6 > 5 > 4 > 3
//   I - I - D - D - D
// Your Task:

// You don't need to read input or print anything. Your task is to complete the function printMinNumberForPattern() which takes the string S and returns a string containing the minimum number following the valid number.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ Length of String ≤ 8

class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string result = "";
        for(int index = 1; index <= pattern.size() + 1; index++){
            result += '0' + index;
        }
        while(true)
        {
            int innerIndex = 1, patternIndex = 0;
            bool isSorted = true;
            while(innerIndex < result.size())
            {
                if(pattern[patternIndex] == 'D' && result[innerIndex] > result[innerIndex - 1])
                {
                    swap(result[innerIndex], result[innerIndex - 1]);
                    isSorted = false;
                } 
                if(pattern[patternIndex] == 'I' && result[innerIndex] < result[innerIndex - 1]){
                    swap(result[innerIndex], result[innerIndex - 1]);
                    isSorted = false;
                }
                innerIndex++;
                patternIndex++;
            }
            if(isSorted == true) break;
        }
        return result;
    }
};
