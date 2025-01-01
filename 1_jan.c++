//Maximum score after splitting a string
//Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).
//The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

/*
Example 1:

Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3
 */

class Solution {
public:
    int maxScore(string s) {
        int length = s.length();
        int maxScore = 0;

        int leftZeros = 0;    // Count of `0`s in the left part
        int rightOnes = 0;    // Count of `1`s in the right part

        // First, calculate total number of `1`s in the right part
        for (char c : s) {
            if (c == '1') rightOnes++;
        }

        // Now, iterate through the string to calculate the score at each split
        for (int i = 0; i < length - 1; i++) { // Split at i, avoid last split
            if (s[i] == '0') leftZeros++;   // Add to left `0`s
            if (s[i] == '1') rightOnes--;   // Subtract from right `1`s

            // Calculate score at this split point
            int currentScore = leftZeros + rightOnes;
            maxScore = max(maxScore, currentScore);  // Update max score
        }

        return maxScore;
    }
};