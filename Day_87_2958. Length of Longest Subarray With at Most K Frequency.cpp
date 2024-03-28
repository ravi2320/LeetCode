/*
2958. Length of Longest Subarray With at Most K Frequency
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums and an integer k.

The frequency of an element x is the number of times it occurs in an array.

An array is called good if the frequency of each element in this array is less than or equal to k.

Return the length of the longest good subarray of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6
Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
It can be shown that there are no good subarrays with length more than 6.
Example 2:

Input: nums = [1,2,1,2,1,2,1,2], k = 1
Output: 2
Explanation: The longest possible good subarray is [1,2] since the values 1 and 2 occur at most once in this subarray. Note that the subarray [2,1] is also good.
It can be shown that there are no good subarrays with length more than 2.
Example 3:

Input: nums = [5,5,5,5,5,5,5], k = 4
Output: 4
Explanation: The longest possible good subarray is [5,5,5,5] since the value 5 occurs 4 times in this subarray.
It can be shown that there are no good subarrays with length more than 4.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= nums.length
*/

/**
 * Intuition:
 * We use a sliding window approach to find the maximum subarray length such that the sum of elements in the subarray is less than or equal to k.
 * We maintain a hashmap to keep track of the frequency of elements in the current window.
 * If the sum of elements in the window exceeds k, we move the left pointer to shrink the window until the sum becomes less than or equal to k.
 * At each step, we update the result with the maximum length of the subarray encountered so far.
 * 
 * Time Complexity: O(n)
 * - We iterate through the array once from left to right, and each element is processed only once.
 * - The inner while loop, which adjusts the window, runs at most n times in total.
 * 
 * Space Complexity: O(n)
 * - We use a hashmap to store the frequency of elements in the current window, which can have at most n distinct elements.
 */
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(); // Get the size of the input array
        int i = 0, j = 0; // Initialize two pointers for the sliding window approach
        unordered_map<int, int> mp; // Create a hashmap to store the frequency of elements in the current window
        int res = 0; // Initialize a variable to store the maximum subarray length
        
        // Iterate through the array using the j pointer
        while(j < n){
            mp[nums[j]]++; // Increment the frequency of the current element
            
            // Shrink the window by moving the left pointer if the sum of elements exceeds k
            while(i < j && mp[nums[j]] > k){
                mp[nums[i]]--; // Decrement the frequency of the element pointed by the left pointer
                i++; // Move the left pointer to the right
            }
            
            // Update the result with the maximum length of the subarray encountered so far
            res = max(res, j - i + 1);
            j++; // Move the right pointer to the right to expand the window
        }
        
        return res; // Return the maximum subarray length
    }
};


/*
Intuition:
We use a sliding window approach to find the maximum length of subarrays where the frequency of any element does not exceed 'k'.
We keep track of the frequency of each element in the current window using a hashmap.
If the frequency of any element exceeds 'k', we shrink the window by moving the left pointer.
Time Complexity: O(N)
Space Complexity: O(N), where N is the size of the input array nums.
*/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(); // Get the size of the input array
        int i = 0, j = 0, res = 0, culprit = 0; // Initialize pointers, result, and culprit count
        unordered_map<int, int> mp; // Create a hashmap to store the frequency of elements in the current window

        // Iterate through the array using the j pointer
        while(j < n){
            mp[nums[j]]++; // Increment the frequency of the current element
            
            // If the frequency of the current element becomes k+1, increment the culprit count
            if(mp[nums[j]] == k+1){
                culprit++;
            }

            // If there are any culprits (elements with frequency exceeding k), shrink the window
            if(culprit > 0){
                mp[nums[i]]--; // Decrement the frequency of the element pointed by the left pointer
                
                // If the frequency of the leftmost element becomes k, decrement the culprit count
                if(mp[nums[i]] == k)
                    culprit--;
                i++; // Move the left pointer to the right
            }

            // If there are no culprits, update the result with the maximum subarray length encountered so far
            if(culprit == 0)
                res = max(res, j - i + 1);
            j++; // Move the right pointer to the right to expand the window
        }

        return res; // Return the maximum subarray length
    }
};
