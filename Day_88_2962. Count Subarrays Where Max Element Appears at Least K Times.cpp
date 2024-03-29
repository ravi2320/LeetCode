/*
2962. Count Subarrays Where Max Element Appears at Least K Times
Solved
Medium
Topics
Companies
You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
Example 2:

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= 105
*/

/* 
 * Intuition:
 * - We initialize a variable 'maxEle' to store the maximum element in the given array 'nums'.
 * - We iterate through the array using two pointers 'i' and 'j'.
 * - We maintain a counter 'maxCnt' to keep track of the count of occurrences of 'maxEle'.
 * - We use the sliding window technique to count the number of subarrays where the maximum element occurs 'k' times.
 * - If 'maxCnt' is greater than or equal to 'k', we update the result by adding the count of subarrays from the current 'j' to the end of the array.
 * - We move the window by incrementing 'i' and decrementing 'maxCnt' until 'maxCnt' becomes less than 'k'.
 * - We return the final result.
 *
 * Time Complexity: O(N), where N is the size of the input array 'nums'.
 * - The algorithm iterates through the array once using two pointers.
 * - The inner while loop may iterate through a portion of the array in the worst case, but its overall complexity is still O(N).
 * - Thus, the time complexity is dominated by the single pass through the array.
 *
 * Space Complexity: O(1)
 * - The algorithm uses a constant amount of extra space, regardless of the size of the input array.
 */

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // Find the maximum element in the array
        int maxEle = *max_element(begin(nums), end(nums));

        long long res = 0;
        int maxCnt = 0;
        int n = nums.size();
        int j = 0, i = 0;

        // Iterate through the array using two pointers
        while(j < n){

            // If the current element is the maximum element, increment the count
            if(nums[j] == maxEle)
                maxCnt++;

            // If the count of the maximum element exceeds or equals 'k', update the result
            while(maxCnt >= k){

                // Update the result by adding the count of subarrays from 'j' to the end of the array
                res += n - j;

                // Move the window by incrementing 'i' and decrementing 'maxCnt'
                if(nums[i] == maxEle)
                    maxCnt--;

                i++;
            }

            // Move the right pointer
            j++;
        }
        return res;
    }
};


/*
 * Intuition:
 * - We find the maximum element in the array and keep track of its indices.
 * - As we iterate through the array, we maintain a vector to store the indices of the maximum element.
 * - Whenever the size of this vector becomes greater than or equal to 'k', we calculate the number of subarrays 
 *   that can be formed with 'k' occurrences of the maximum element.
 * - We add the count of subarrays for each occurrence of the maximum element, considering it as the ending point of the subarray.
 * - Finally, we return the total count of subarrays.
 * 
 * Time Complexity: O(N)
 * - The algorithm iterates through the array once, so the time complexity is linear.
 * 
 * Space Complexity: O(N)
 * - We use an additional vector to store the indices of the maximum element, which can grow up to the size of the input array.
 */

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // Find the maximum element in the array
        int maxEle = *max_element(begin(nums), end(nums));
        int n = nums.size();
        long long res = 0;
        vector<int> maxEleIndices;
        
        // Iterate through the array
        for(int i = 0; i < n; i++) {
            // If the current element is the maximum element, store its index
            if(nums[i] == maxEle)
                maxEleIndices.push_back(i);

            int size = maxEleIndices.size();
            
            // Check if the size of maxEleIndices is greater than or equal to k
            if(size >= k) {
                // If yes, calculate the number of subarrays for the kth occurrence of the maximum element
                int last_index = maxEleIndices[size - k];
                res += last_index + 1; // Increment by 1 as the index is 0-based
            }
        }
        return res;
    }
};
