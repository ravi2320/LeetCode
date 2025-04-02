/*
2873. Maximum Value of an Ordered Triplet I
Solved
Easy
Topics
Companies
Hint
You are given a 0-indexed integer array nums.

Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.

The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

 

Example 1:

Input: nums = [12,6,1,2,7]
Output: 77
Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77. 
Example 2:

Input: nums = [1,10,3,4,19]
Output: 133
Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.
Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.
 

Constraints:

3 <= nums.length <= 100
1 <= nums[i] <= 106
*/

/*
Approach:
1. **Brute Force (Three Nested Loops)**:
   - Iterate over all possible triplets `(i, j, k)` where `i < j < k`.
   - Compute the value `(nums[i] - nums[j]) * nums[k]` for each triplet.
   - Keep track of the maximum value obtained.

Intuition:
- Since we need to find the **maximum triplet value**, we must check all possible combinations.
- The naive approach involves three loops to explore all triplets.

Time Complexity: **O(n³)** - Three nested loops make this inefficient for large `n`.
Space Complexity: **O(1)** - Only a few integer variables are used.

This approach is inefficient and can be optimized.
*/

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;

        // Iterate over all triplets (i, j, k)
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                long long cal = nums[i] - nums[j]; // Compute (nums[i] - nums[j])
                
                for(int k = j + 1; k < n; k++) {
                    res = max(res, cal * nums[k]); // Multiply with nums[k] and update max
                }
            }
        }

        return res; // Return the maximum triplet value found
    }
};

/*
Approach:
1. **Precompute LeftMax and RightMax**:
   - `leftMax[i]`: Stores the maximum value from `nums[0]` to `nums[i-1]`.
   - `rightMax[i]`: Stores the maximum value from `nums[i+1]` to `nums[n-1]`.

2. **Iterate through the array**:
   - For each `i` (excluding first and last index), compute `(leftMax[i] - nums[i]) * rightMax[i]`.
   - Update the maximum result.

Intuition:
- Instead of using three nested loops, we precompute the left and right max arrays.
- This allows us to efficiently find the best triplet value in **O(n)** time.

Time Complexity: **O(n)** - We traverse the array 3 times.
Space Complexity: **O(n)** - We use two extra arrays (`leftMax` and `rightMax`).

This is an optimized approach compared to the brute force **O(n³)** solution.
*/

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        // Arrays to store maximum values on left and right
        vector<int> leftMax(n, 0), rightMax(n, 0);

        // Compute left max values
        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
            rightMax[n - i - 1] = max(rightMax[n - i], nums[n - i]);
        }

        long long res = 0;

        // Compute the maximum triplet value
        for(int i = 1; i < n - 1; i++) {
            long long cal = (long long)(leftMax[i] - nums[i]) * rightMax[i];
            res = max(res, cal);
        }

        return res; // Return the maximum triplet value found
    }
};

/*
Approach:
1. **Track Maximum Element (`maxi`)**:
   - Keeps track of the maximum element encountered so far.

2. **Track Maximum Difference (`maxDiff`)**:
   - Stores the maximum value of (`maxi - nums[k]`) for valid indices.

3. **Iterate Over the Array**:
   - For each `k`, update `res` with `maxDiff * nums[k]`.
   - Update `maxDiff` as the best difference found so far.
   - Update `maxi` to track the highest number encountered.

Intuition:
- Instead of using nested loops, we optimize by keeping track of required values dynamically.
- This avoids recomputation and reduces complexity to **O(n)**.

Time Complexity: **O(n)** - We iterate through the array once.
Space Complexity: **O(1)** - Only a few variables are used.
*/

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        long long maxi = 0;      // Stores maximum value seen so far
        long long maxDiff = 0;   // Stores max value of (maxi - nums[k])
        long long res = 0;       // Stores the maximum triplet value

        for(int k = 0; k < n; k++) {
            res = max(res, maxDiff * nums[k]);  // Update result with the best triplet found
            maxDiff = max(maxDiff, maxi - nums[k]); // Update max difference
            maxi = max(maxi, (long long)nums[k]);   // Update max element seen so far
        }

        return res; // Return the maximum triplet value found
    }
};