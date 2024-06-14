/*
945. Minimum Increment to Make Array Unique
Solved
Medium
Topics
Companies
You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

Return the minimum number of moves to make every value in nums unique.

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,2]
Output: 1
Explanation: After 1 move, the array could be [1, 2, 3].
Example 2:

Input: nums = [3,2,1,2,1,7]
Output: 6
Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
*/ 

/*
Intuition:
- To make all elements in the array unique with the minimum number of increments, we can first sort the array.
- By sorting the array, we can easily compare each element with the previous one and ensure it is greater.
- If the current element is not greater than the previous one, we increment it to be exactly one more than the previous element.
- This ensures that we perform the minimum increments necessary to make all elements unique.

Approach:
1. Sort the array.
2. Traverse the sorted array starting from the second element.
3. For each element, check if it is not greater than the previous element.
4. If it is not, increment it to be one more than the previous element and add the increment to the total number of moves.
5. Continue this process for the entire array.
6. Return the total number of moves.

Time Complexity:
- O(n log n) due to the sorting step.
- O(n) for the traversal, making the overall time complexity O(n log n).

Space Complexity:
- O(1), since we are using a constant amount of extra space.

*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i++){
            if(nums[i-1] >= nums[i]){
                ans += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1] + 1;
            }
        }
        return ans;
    }
};
