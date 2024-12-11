/*
1004. Max Consecutive Ones III
Solved
Medium
Topics
Companies
Hint
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
*/

/*
Approach:
1. Use the sliding window (two-pointer) technique to maintain a subarray with at most `k` zeroes.
2. Expand the window by moving the `j` pointer to include elements.
3. If the count of zeroes in the current window exceeds `k`, shrink the window by moving the `i` pointer until the condition is satisfied.
4. Track the maximum length of the valid subarray.

Steps:
- Initialize pointers `i` and `j` for the sliding window and variables `zero` to count zeroes and `maxLen` for the result.
- Traverse the array with the `j` pointer:
  - Increment `zero` if the current element is `0`.
  - If `zero > k`, increment `i` and adjust the count of `zero`.
  - Update `maxLen` with the current window size (`j - i + 1`) if the window is valid.

Time Complexity:
- O(n): Each element is processed at most twice (once by `j` and once by `i`).

Space Complexity:
- O(1): Constant extra space.

Edge Cases:
- All elements are `1`.
- All elements are `0` and `k` is sufficient to flip all.
- `k = 0`.

*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0; // Sliding window pointers
        int maxLen = 0;   // Maximum length of subarray
        int zero = 0;     // Count of zeroes in the current window

        // Traverse the array
        while (j < n) {
            // Include nums[j] in the window
            if (nums[j] == 0) {
                zero++;
            }

            // If the number of zeroes exceeds k, shrink the window
            while (zero > k) {
                if (nums[i] == 0) {
                    zero--;
                }
                i++; // Move the left pointer
            }

            // Update the maximum length of the valid window
            maxLen = max(maxLen, j - i + 1);
            
            // Expand the window
            j++;
        }

        return maxLen;
    }
};


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int maxLen = 0, zero = 0;

        while(j < n){

            if(nums[j] == 0){
                zero++;
            }

            if(zero > k){
                if(nums[i] == 0){
                    zero--;
                }
                i++;
            }

            if(zero <= k){
                maxLen = max(maxLen, j-i+1);
            }

            j++;
        }

        return maxLen;
    }
};