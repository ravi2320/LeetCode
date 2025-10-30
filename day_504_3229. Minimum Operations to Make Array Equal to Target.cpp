/*
3229. Minimum Operations to Make Array Equal to Target

avatar
Discuss Approach
arrow-up
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given two positive integer arrays nums and target, of the same length.

In a single operation, you can select any subarray of nums and increment each element within that subarray by 1 or decrement each element within that subarray by 1.

Return the minimum number of operations required to make nums equal to the array target.

 

Example 1:

Input: nums = [3,5,1,2], target = [4,6,2,4]

Output: 2

Explanation:

We will perform the following operations to make nums equal to target:
- Increment nums[0..3] by 1, nums = [4,6,2,3].
- Increment nums[3..3] by 1, nums = [4,6,2,4].

Example 2:

Input: nums = [1,3,2], target = [2,1,4]

Output: 5

Explanation:

We will perform the following operations to make nums equal to target:
- Increment nums[0..0] by 1, nums = [2,3,2].
- Decrement nums[1..1] by 1, nums = [2,2,2].
- Decrement nums[1..1] by 1, nums = [2,1,2].
- Increment nums[2..2] by 1, nums = [2,1,3].
- Increment nums[2..2] by 1, nums = [2,1,4].

 

Constraints:

1 <= nums.length == target.length <= 105
1 <= nums[i], target[i] <= 108
*/

// Intuition:
// The problem asks for the minimum number of operations to make the `nums` array equal to the `target` array.
// The operations consist of adjusting elements in `nums` based on the differences between corresponding elements 
// in `nums` and `target`. The key observation is that a change in the sign of the difference (from positive to negative 
// or vice versa) indicates a new operation. Also, when continuing in the same direction (e.g., both are positive or both are negative),
// only the difference in magnitudes of the elements matters.

// Approach:
// 1. First, calculate the difference between corresponding elements in `nums` and `target` and store it in the `diff` array.
// 2. Then, traverse through the `diff` array and track when a new operation is needed based on changes in the sign of the difference. 
//    We also accumulate the total number of operations based on the magnitude of differences.
// 3. For each transition in the sign, we count the magnitude of the difference.
// 4. For cases where the sign remains the same, we consider the difference in magnitudes of the current and previous elements.

// Time Complexity:
// - O(n), where n is the size of the input arrays `nums` and `target`. 
// - We traverse the arrays twice: once to compute the differences and once to accumulate the operations.


// Space Complexity:
// - O(n), where n is the size of the input arrays `nums` and `target`. 
// - We use an additional `diff` array of size n to store the differences between corresponding elements.

class Solution {
public:
    // Function to calculate minimum operations to convert `nums` to `target`
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();  // Get the size of the input arrays
        vector<int> diff(n);  // Create an array to store the differences between nums and target

        // Calculate the difference between corresponding elements of nums and target
        for(int i = 0; i < n; i++) {
            diff[i] = nums[i] - target[i];  // Store the difference in the diff array
        }

        int prev = 0;  // Previous difference, initialized to 0
        long long operations = 0;  // Variable to accumulate the total number of operations required

        // Traverse through the diff array to calculate the operations
        for(int &curr : diff) {
            // If there's a sign change (from negative to positive or vice versa), we need to perform operations
            if((prev < 0 && curr > 0) || (prev > 0 && curr < 0)){
                operations += abs(curr);  // Add the magnitude of the current difference to operations
            }
            // If there's no sign change but the magnitude of the current difference is larger, adjust accordingly
            else if(abs(curr) > abs(prev)){
                operations += abs(curr) - abs(prev);  // Add the difference in magnitudes to operations
            }

            prev = curr;  // Update the previous difference for the next iteration
        }

        return operations;  // Return the total number of operations required
    }
};
