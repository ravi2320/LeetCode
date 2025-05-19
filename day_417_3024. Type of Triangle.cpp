/*
3024. Type of Triangle
Solved
Easy
Topics
Companies
Hint
You are given a 0-indexed integer array nums of size 3 which can form the sides of a triangle.

A triangle is called equilateral if it has all sides of equal length.
A triangle is called isosceles if it has exactly two sides of equal length.
A triangle is called scalene if all its sides are of different lengths.
Return a string representing the type of triangle that can be formed or "none" if it cannot form a triangle.

 

Example 1:

Input: nums = [3,3,3]
Output: "equilateral"
Explanation: Since all the sides are of equal length, therefore, it will form an equilateral triangle.
Example 2:

Input: nums = [3,4,5]
Output: "scalene"
Explanation: 
nums[0] + nums[1] = 3 + 4 = 7, which is greater than nums[2] = 5.
nums[0] + nums[2] = 3 + 5 = 8, which is greater than nums[1] = 4.
nums[1] + nums[2] = 4 + 5 = 9, which is greater than nums[0] = 3. 
Since the sum of the two sides is greater than the third side for all three cases, therefore, it can form a triangle.
As all the sides are of different lengths, it will form a scalene triangle.
 

Constraints:

nums.length == 3
1 <= nums[i] <= 100
*/

/*
Approach:
- Given the lengths of three sides, determine the type of triangle:
    - "none": if it does not form a valid triangle (violates triangle inequality).
    - "equilateral": all three sides are equal.
    - "isosceles": exactly two sides are equal.
    - "scalene": all three sides are different.

Intuition:
- Triangle inequality: sum of any two sides must be greater than the third.
- Compare sides for equality to classify type.

Time Complexity: O(1) — constant time checks.
Space Complexity: O(1) — uses only a few variables.
*/

class Solution {
public:
    string triangleType(vector<int>& nums) {
        // Check for triangle validity using triangle inequality
        if ((nums[0] + nums[1] <= nums[2]) ||
            (nums[0] + nums[2] <= nums[1]) ||
            (nums[1] + nums[2] <= nums[0])) {
            return "none";
        }

        // All sides equal → equilateral
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }

        // All sides different → scalene
        if (nums[0] != nums[1] && nums[1] != nums[2] && nums[0] != nums[2]) {
            return "scalene";
        }

        // Otherwise → isosceles (exactly two sides equal)
        return "isosceles";
    }
};
