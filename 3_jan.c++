/*
You are given a 0-indexed integer array nums of length n.

nums contains a valid split at index i if the following are true:

The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
There is at least one element to the right of i. That is, 0 <= i < n - 1.
Return the number of valid splits in nums.

 

Example 1:

Input: nums = [10,4,-8,7]
Output: 2
Explanation: 
There are three ways of splitting nums into two non-empty parts:
- Split nums at index 0. Then, the first part is [10], and its sum is 10. The second part is [4,-8,7], and its sum is 3. Since 10 >= 3, i = 0 is a valid split.
- Split nums at index 1. Then, the first part is [10,4], and its sum is 14. The second part is [-8,7], and its sum is -1. Since 14 >= -1, i = 1 is a valid split.
- Split nums at index 2. Then, the first part is [10,4,-8], and its sum is 6. The second part is [7], and its sum is 7. Since 6 < 7, i = 2 is not a valid split.
Thus, the number of valid splits in nums is 2.
*/




//BRUTE APPROCHE
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        // Prefix sum array to store cumulative sums
        vector<long long> prefSum(n);
        prefSum[0] = nums[0];

        // Build prefix sum array
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        int count = 0;
        // Check each possible split position
        for (int i = 0; i < n - 1; i++) {
            // Sum of left part (0 to i)
            long long leftSum = prefSum[i];
            // Sum of right part (i+1 to n-1)
            long long rightSum = prefSum[n - 1] - prefSum[i];

            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
};
//TC = O(N);
//SC = O(N);

//BETTER APPROCH
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long rightsum = 0;
        int cnt = 0;

        // Calculate total sum of the array and initialize rightsum
        for (int num : nums) {
            rightsum += num;
        }

        long long leftsum = 0;

        // Iterate through the array
        for (int i = 0; i < n - 1; i++) { // Stop at n-1 to ensure two non-empty parts
            leftsum += nums[i];       // Incrementally update leftsum
            rightsum -= nums[i];      // Decrement rightsum as leftsum grows
            if (leftsum >= rightsum) {
                cnt++; // Increment count if the split is valid
            }
        }

        return cnt;
    }
};
//TC = O(N);
//SC = O(1);