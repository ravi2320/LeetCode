/*
18. 4Sum
Solved
Medium
Topics
Companies
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

/*
Intuition:
- The problem requires finding all unique quadruplets in an array that sum up to a given target.
- To optimize, we can use sorting and two-pointer techniques to reduce the time complexity.
- By fixing two numbers and using a two-pointer approach for the other two numbers, we can efficiently find the quadruplets.

Approach:
1. Sort the array.
2. Use two nested loops to fix the first two numbers.
3. Use the two-pointer technique to find the other two numbers.
4. Skip duplicates to ensure all quadruplets are unique.

Time Complexity:
- O(n^3): Sorting the array takes O(n log n), and the three nested loops take O(n^3) in the worst case.
  Thus, the overall time complexity is dominated by O(n^3).

Space Complexity:
- O(n): For storing the output and the additional space for sorting in place.

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        // Sort the array to use two-pointer technique
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicate elements for the second number
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        // Skip duplicate elements for the third number
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        // Skip duplicate elements for the fourth number
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } 
                    else if (sum < target) {
                        left++;
                    } 
                    else {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};
