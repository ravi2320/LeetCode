/*
976. Largest Perimeter Triangle

Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

 

Example 1:

Input: nums = [2,1,2]
Output: 5
Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
Example 2:

Input: nums = [1,2,1,10]
Output: 0
Explanation: 
You cannot use the side lengths 1, 1, and 2 to form a triangle.
You cannot use the side lengths 1, 1, and 10 to form a triangle.
You cannot use the side lengths 1, 2, and 10 to form a triangle.
As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.
 

Constraints:

3 <= nums.length <= 104
1 <= nums[i] <= 106
*/

/*
Approach:
1. Sort the array of side lengths.
2. Traverse through triplets of consecutive elements (nums[i], nums[i+1], nums[i+2]).
3. For each triplet, check the triangle inequality: nums[i] + nums[i+1] > nums[i+2].
   - If true, compute the perimeter and update the maximum.
4. Return the maximum perimeter found.

Intuition:
- To form a triangle, the sum of any two sides must be greater than the third side.
- Sorting ensures nums[i], nums[i+1], nums[i+2] are in non-decreasing order, so we only need to check one condition: nums[i] + nums[i+1] > nums[i+2].
- We scan all possible consecutive triplets and take the maximum valid perimeter.

Time Complexity:
- O(n log n) for sorting + O(n) for scanning triplets → O(n log n) overall.
Space Complexity:
- O(1), as we only use a few variables apart from sorting in-place.

*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());  // sort to apply triangle property easily

        for(int i = 0; i < n - 2; i++) {
            if(nums[i] + nums[i+1] > nums[i+2]) {
                ans = max(ans, nums[i] + nums[i+1] + nums[i+2]);
            }
        }

        return ans;
    }
};
