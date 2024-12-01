/*
2104. Sum of Subarray Ranges
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
 

Constraints:

1 <= nums.length <= 1000
-109 <= nums[i] <= 109
*/

/*
Approach:
1. **Range Contributions**:
   - For each element in the array, calculate its contribution as the minimum and maximum element in all subarrays where it appears.
   - Use the following:
     - `pse[i]` (Previous Smaller Element): Index of the nearest smaller element to the left of `nums[i]`.
     - `nse[i]` (Next Smaller Element): Index of the nearest smaller element to the right of `nums[i]`.
     - `pge[i]` (Previous Greater Element): Index of the nearest greater element to the left of `nums[i]`.
     - `nge[i]` (Next Greater Element): Index of the nearest greater element to the right of `nums[i]`.

2. **Formula**:
   - The contribution of `nums[i]` as the minimum element: `(i - pse[i]) * (nse[i] - i) * nums[i]`.
   - The contribution of `nums[i]` as the maximum element: `(i - pge[i]) * (nge[i] - i) * nums[i]`.

3. **Implementation**:
   - Use stacks to calculate `pse`, `nse`, `pge`, and `nge` in O(n).
   - Compute the total sum of all ranges.

Time Complexity:
- **O(n)**: Calculating all arrays and contributions is linear.

Space Complexity:
- **O(n)**: Stacks and auxiliary arrays for indices.

*/

class Solution {
public:
    // Function to compute the sum of subarray ranges
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, n), pge(n, -1), nse(n, n), pse(n, -1);
        stack<int> st1, st2;

        // Compute Previous Smaller Element (pse) and Previous Greater Element (pge)
        for (int i = 0; i < n; i++) {
            while (!st1.empty() && nums[st1.top()] >= nums[i]) {
                st1.pop();
            }
            while (!st2.empty() && nums[st2.top()] <= nums[i]) {
                st2.pop();
            }
            if (!st1.empty()) pse[i] = st1.top();
            if (!st2.empty()) pge[i] = st2.top();
            st1.push(i);
            st2.push(i);
        }

        // Clear stacks for reuse
        while (!st1.empty()) st1.pop();
        while (!st2.empty()) st2.pop();

        // Compute Next Smaller Element (nse) and Next Greater Element (nge)
        for (int i = n - 1; i >= 0; i--) {
            while (!st1.empty() && nums[st1.top()] > nums[i]) {
                st1.pop();
            }
            while (!st2.empty() && nums[st2.top()] < nums[i]) {
                st2.pop();
            }
            if (!st1.empty()) nse[i] = st1.top();
            if (!st2.empty()) nge[i] = st2.top();
            st1.push(i);
            st2.push(i);
        }

        // Calculate the result using the contributions of each element
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long mini = (long long)((i - pse[i]) * (nse[i] - i)) * nums[i];
            long long maxi = (long long)((i - pge[i]) * (nge[i] - i)) * nums[i];
            ans += maxi - mini;
        }

        return ans;
    }
};
