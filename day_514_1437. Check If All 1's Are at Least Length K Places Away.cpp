/*
1437. Check If All 1's Are at Least Length K Places Away

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.

 

Example 1:


Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
Example 2:


Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.
 

Constraints:

1 <= nums.length <= 105
0 <= k <= nums.length
nums[i] is 0 or 1
*/

// Intuition:
// The problem asks us to check if the 1's in the binary array are at least `k` positions apart. 
// We need to iterate through the array and track the distance between consecutive 1's. 
// If at any point, the distance between two consecutive 1's is less than `k`, we return false.
// If the entire array satisfies the condition, we return true.

// Approach:
// 1. We initialize a counter `cnt` to track the distance between consecutive 1's. We set it to a large value initially (1e6).
// 2. We iterate through the array, and each time we encounter a 1, we check if the previous 1 was closer than `k` positions.
// 3. If the previous 1 was too close, we return false immediately.
// 4. Otherwise, we reset the counter and continue scanning.
// 5. If we finish scanning the array without returning false, we return true because all 1's are sufficiently spaced.

class Solution {
public:
    // Function to check if the 1's in the array are at least `k` positions apart
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt = 1e6;  // Initialize a counter for the distance between consecutive 1's.
        int n = nums.size();  // Size of the input array
        
        // Iterate through each element of the array
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {  // If we encounter a 1
                if(cnt < k)  // Check if the previous 1 was less than `k` positions away
                    return false;  // If the distance is less than `k`, return false
                else
                    cnt = 0;  // Reset counter since we've found a new 1
            }
            else {
                cnt++;  // If it's a 0, increase the distance counter
            }
        }

        return true;  // If we finished the loop without issues, return true
    }
};

/* Time Complexity:
   - We are iterating over the array once, so the time complexity is O(n), where `n` is the size of the input array.
   
   Space Complexity:
   - We are using a constant amount of extra space (for variables like `cnt` and `n`), so the space complexity is O(1).
*/
