/*
2654. Minimum Number of Operations to Make All Array Elements Equal to 1

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a 0-indexed array nums consisiting of positive integers. You can do the following operation on the array any number of times:

Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.

The gcd of two integers is the greatest common divisor of the two integers.

 

Example 1:

Input: nums = [2,6,3,4]
Output: 4
Explanation: We can do the following operations:
- Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
- Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
- Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
- Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].
Example 2:

Input: nums = [2,10,6,14]
Output: -1
Explanation: It can be shown that it is impossible to make all the elements equal to 1.
 

Constraints:

2 <= nums.length <= 50
1 <= nums[i] <= 106
*/

/*
Intuition:
The problem is to find the minimum number of operations needed to make all elements in the array equal to 1, where in each operation we can select a contiguous subarray and set all its elements to their GCD.

Approach:
1. First, count the number of `1`s in the array. If there are any `1`s, the minimum number of operations is simply the length of the array minus the count of `1`s, because you only need to change the other elements to 1.
   
2. If there are no `1`s, we need to find the smallest subarray with a GCD of `1`. The reasoning is that we can reduce the GCD of this subarray to `1`, and then continue applying operations to the rest of the array. The smallest such subarray would minimize the number of operations.
   
3. We iterate through all possible subarrays and calculate their GCD. Once we find a subarray with GCD equal to `1`, we record the length of the subarray. The goal is to minimize this length.

4. If no subarray has GCD `1`, then it's impossible to reduce the entire array to `1`, and we return `-1`.

Time Complexity:
- The main loop runs over each element of the array, and for each element, we calculate the GCD of all possible subarrays starting from that element. This results in a time complexity of O(n^2), where `n` is the length of the array.
- Calculating GCD takes O(log(maxElement)) time, but since it's nested inside two loops, it doesn't change the overall O(n^2) complexity.

Space Complexity:
- The space complexity is O(1) because we are using only a few integer variables for storage. The input array `nums` is modified in-place, and we do not use any additional data structures.
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), cnt = 0;

        // Step 1: Count how many `1`s are in the array
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1)
                cnt++;  // Increment count if the element is `1`
        }

        // Step 2: If we have any `1`s, the minimum number of operations is (n - cnt)
        // because all the other elements can be transformed to `1`s
        if(cnt > 0) {
            return (n - cnt);
        }

        // Step 3: If no `1`s, find the smallest subarray with GCD 1
        int minOperations = INT_MAX;

        // Iterate over each possible starting point for the subarrays
        for(int i = 0; i < n; i++) {
            int GCD = nums[i];  // Start with the current element as the GCD

            // Try extending the subarray to the right
            for(int j = i + 1; j < n; j++) {
                // Update GCD with the new element
                GCD = __gcd(GCD, nums[j]);

                // If we find a subarray with GCD = 1, update the result
                if(GCD == 1) {
                    minOperations = min(minOperations, j - i);  // Minimize the length of the subarray
                    break;  // No need to check further for this starting point
                }
            }
        }

        // Step 4: If no valid subarray with GCD 1 was found, return -1
        if(minOperations == INT_MAX)
            return -1;

        // Step 5: Return the minimum operations required
        // The number of operations is the minimum length subarray with GCD 1 plus the remaining elements (n-1)
        return minOperations + (n - 1);
    }
};
