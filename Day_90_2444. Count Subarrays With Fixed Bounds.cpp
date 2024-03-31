/*
2444. Count Subarrays With Fixed Bounds
Solved
Hard
Topics
Companies
Hint
You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
Example 2:

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
 

Constraints:

2 <= nums.length <= 105
1 <= nums[i], minK, maxK <= 106
*/

/*
Intuition:
- Iterate through the array.
- Keep track of the positions of the last occurrence of the minimum element (minK) and the maximum element (maxK) seen so far.
- Keep track of the position of the last element outside the range [minK, maxK] (culprit).
- For each element, calculate the length of the subarray that satisfies the condition (within the range [minK, maxK]).
- Add up the lengths of all such subarrays.

Time Complexity: O(N)
- We iterate through the array once, performing constant-time operations in each iteration.

Space Complexity: O(1)
- We use only a constant amount of additional space regardless of the input array size.
*/

#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;

        // Initialize variables to track the positions of minK, maxK, and the last element outside the range [minK, maxK].
        int minPos = -1;
        int maxPos = -1;
        int culprit = -1;

        // Iterate through the array
        for(int i = 0; i < nums.size(); i++){

            // Update culprit if the current element is outside the range [minK, maxK]
            if(nums[i] < minK || nums[i] > maxK)
                culprit = i;

            // Update minPos if the current element is equal to minK
            if(nums[i] == minK)
                minPos = i;

            // Update maxPos if the current element is equal to maxK
            if(nums[i] == maxK)
                maxPos = i;

            // Calculate the length of the subarray satisfying the condition
            long long smaller = min(minPos, maxPos);
            long long temp = smaller - culprit;

            // Add the length to the total count if it's positive (non-empty subarray)
            ans += (temp <= 0) ? 0 : temp;
        }

        // Return the total count
        return ans;
    }
};
