/*
2221. Find Triangular Sum of an Array

You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 (inclusive).

The triangular sum of nums is the value of the only element present in nums after the following process terminates:

Let nums comprise of n elements. If n == 1, end the process. Otherwise, create a new 0-indexed integer array newNums of length n - 1.
For each index i, where 0 <= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) % 10, where % denotes modulo operator.
Replace the array nums with newNums.
Repeat the entire process starting from step 1.
Return the triangular sum of nums.

 

Example 1:


Input: nums = [1,2,3,4,5]
Output: 8
Explanation:
The above diagram depicts the process from which we obtain the triangular sum of the array.
Example 2:

Input: nums = [5]
Output: 5
Explanation:
Since there is only one element in nums, the triangular sum is the value of that element itself.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 9
*/

/*
Approach:
1. Start with the initial array `nums` as the first row.
2. Iteratively build the next row by summing adjacent elements modulo 10.
3. After each iteration, reduce the size of the array by 1.
4. Continue until only one element remains, which is the triangular sum.

Intuition:
This problem simulates constructing a "triangle" of numbers:
- Each new row is built by combining adjacent numbers from the row above.
- Eventually, all elements collapse into a single number.
The modulo 10 ensures values always remain between 0–9.

Time Complexity: O(n^2)  
- In iteration 1 → (n-1) operations, iteration 2 → (n-2), ..., total ~ n*(n-1)/2 ≈ O(n^2).
Space Complexity: O(n)  
- We only maintain the current and previous row at any time.
*/

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev = nums;  // store previous row

        // Iteratively reduce array size until 1 element remains
        for(int i = 0; i < n; i++) {
            vector<int> curr;  // next row

            // Generate new row using adjacent pair sums modulo 10
            for(int j = 0; j < n - i - 1; j++) {
                int temp = (prev[j] + prev[j+1]) % 10;
                curr.push_back(temp);
            }

            prev = curr;  // move to next row
        }   

        return prev[0];  // final single element
    }
};

/*
Approach:
1. Instead of creating new arrays for each row, update the original array `nums` in place.
2. For each iteration, compute the sum of adjacent elements modulo 10 and overwrite the left element.
3. After n iterations, only one element remains at nums[0], which is the triangular sum.

Intuition:
- This is essentially building a Pascal-like triangle by repeatedly collapsing adjacent pairs.
- The difference from the earlier version is that we reuse the given array, saving extra space.
- Since only the first (n - i - 1) elements are updated in each step, correctness is preserved.

Time Complexity: O(n^2)  
- Total updates: (n-1) + (n-2) + ... + 1 = O(n^2).
Space Complexity: O(1)  
- Done in-place, no extra space needed.
*/

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        // Iteratively reduce array size until 1 element remains
        for(int i = 0; i < n; i++) {
            // Update nums in-place for current row
            for(int j = 0; j < n - i - 1; j++) {
                nums[j] = (nums[j] + nums[j+1]) % 10;
            }
        }   

        return nums[0];  // final answer
    }
};
