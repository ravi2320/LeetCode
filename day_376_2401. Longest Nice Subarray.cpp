/*
2401. Longest Nice Subarray
Solved
Medium
Topics
Companies
Hint
You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.

 

Example 1:

Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.
Example 2:

Input: nums = [3,1,5,11,13]
Output: 1
Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

/*
Approach:
---------
- A subarray is "nice" if for any two elements, bitwise AND is 0 (no overlapping bits).
- Use two nested loops:
    1. Outer loop picks start index i.
    2. Inner loop checks each j >= i:
        - Maintain a mask for OR of all elements in subarray.
        - If (mask & nums[j]) != 0, break (not nice).
        - Else, update mask and track max length.

Intuition:
----------
- Brute force by checking all subarrays.
- Bitmasking efficiently checks overlapping bits.

Time Complexity: O(n^2)
-----------------------
- Outer loop runs n times.
- Inner loop may run up to n times.

Space Complexity: O(1)
----------------------
- Only a few integer variables used.
*/

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0; // To store result
        
        // Outer loop to fix starting point
        for(int i = 0; i < n; i++) {
            int mask = 0; // Mask to store OR of current subarray
            
            // Inner loop to extend subarray
            for(int j = i; j < n; j++) {
                
                // If overlapping bits found, break
                if((mask & nums[j]) != 0) {
                    break;
                }
                
                // Update mask and result
                mask |= nums[j];
                res = max(res, j - i + 1);
            }
        }
        
        return res;
    }
};


/*
Approach:
---------
- Use sliding window with two pointers (i, j) to maintain a valid window.
- Maintain a mask (bit OR of current window elements):
    - For each nums[j], check if (mask & nums[j]) != 0:
        -> Conflict found (overlapping bits), shrink window from left.
        -> Remove nums[i] from mask using XOR, increment i.
    - Else, add nums[j] to mask using OR.
- Update max length each time.

Intuition:
----------
- Keeps window always valid (no overlapping bits).
- Efficiently processes each element at most twice.

Time Complexity: O(n)
-----------------------
- Each element is added and removed at most once.
- Sliding window approach.

Space Complexity: O(1)
-----------------------
- Only constant extra variables used.
*/

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int mask = 0; // Bitmask to store OR of current window
        int i = 0, j = 0; // Window pointers
        int res = 0; // To store result
        
        // Loop to expand window
        while(j < n) {
            // If overlapping bits, shrink window
            while(i < j && (mask & nums[j]) != 0) {
                mask ^= nums[i]; // Remove nums[i] from mask
                i++;
            }
            
            // Update result and expand window
            mask |= nums[j];
            res = max(res, j - i + 1);
            j++;
        }   
        
        return res;
    }
};