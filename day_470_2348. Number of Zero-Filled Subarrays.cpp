/*
2348. Number of Zero-Filled Subarrays

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation: 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
Example 2:

Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.
Example 3:

Input: nums = [2,10,2019]
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

/*
Approach:
-----------
1. Traverse the array while counting consecutive zeroes.
2. Whenever a non-zero element is encountered:
   - Add the number of subarrays formed by the current streak of zeros using the formula:
     total_subarrays = (cnt * (cnt + 1)) / 2
   - Reset the counter `cnt` to 0.
3. After the loop, if there are still consecutive zeros left at the end, add their contribution.
4. Return the total count.

Intuition:
-----------
- Each consecutive block of `k` zeros can form multiple subarrays.
- For example, if we have 3 zeros `[0,0,0]`, then subarrays are:
   [0], [0], [0], [0,0], [0,0], [0,0,0] → 6 subarrays.
- Formula `(k * (k+1))/2` directly gives the number of subarrays in a block of size `k`.

Time Complexity:
----------------
- O(n): A single pass through the array is enough.
- O(1): Constant extra space is used.

Space Complexity:
-----------------
- O(1): Only a few variables are maintained.
*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int n = nums.size();         // Size of input array
        long long ans = 0;           // To store total zero-filled subarrays
        long long cnt = 0;           // To count consecutive zeros

        // Traverse through the array
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                // If current element is zero, increase streak length
                cnt++;
            }
            else{
                // If current element is non-zero, add the contribution of the streak
                ans += (cnt * (cnt + 1)) / 2;
                cnt = 0;  // Reset streak counter
            }
        }

        // Add contribution of any remaining zero streak at the end
        if(cnt) ans += (cnt * (cnt + 1)) / 2;
    
        return ans;  // Return total zero-filled subarrays
    }
};

														 
/*
Approach:
-----------
1. Traverse the array while counting consecutive zeroes.
2. Whenever a non-zero element is encountered:
   - Add the number of subarrays formed by the current streak of zeros using the formula:
     total_subarrays = (cnt * (cnt + 1)) / 2
   - Reset the counter `cnt` to 0.
3. After the loop, if there are still consecutive zeros left at the end, add their contribution.
4. Return the total count.

Intuition:
-----------
- Each consecutive block of `k` zeros can form multiple subarrays.
- For example, if we have 3 zeros `[0,0,0]`, then subarrays are:
   [0], [0], [0], [0,0], [0,0], [0,0,0] → 6 subarrays.
- Formula `(k * (k+1))/2` directly gives the number of subarrays in a block of size `k`.

Time Complexity:
----------------
- O(n): A single pass through the array is enough.
- O(1): Constant extra space is used.

Space Complexity:
-----------------
- O(1): Only a few variables are maintained.
*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int n = nums.size();         // Size of input array
        long long ans = 0;           // To store total zero-filled subarrays
        long long cnt = 0;           // To count consecutive zeros

        // Traverse through the array
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                // If current element is zero, increase streak length
                cnt++;
            }
            else{
                // If current element is non-zero, add the contribution of the streak
                ans += (cnt * (cnt + 1)) / 2;
                cnt = 0;  // Reset streak counter
            }
        }

        // Add contribution of any remaining zero streak at the end
        if(cnt) ans += (cnt * (cnt + 1)) / 2;
    
        return ans;  // Return total zero-filled subarrays
    }
};

														 
/*
Approach:
------------
We want to count the number of subarrays that consist only of zeros.  
Instead of explicitly calculating the contribution of each streak of zeros at the end,  
we can use a running counter `cnt` to track the length of the current zero streak.

1. Traverse through the array.
2. If the current element is `0`, increase `cnt` by 1, meaning a new zero subarray can be formed ending here.
   - Each new zero extends all previous zero subarrays by one and also forms a new one itself.
   - So, add `cnt` to `ans`.
3. If the current element is not zero, reset `cnt` to 0 since the streak ends.
4. Return `ans`.

Intuition:
------------
Every zero element can be thought of as extending all the zero subarrays formed before it.
For example, in `[0, 0, 0]`:
- At first `0` → 1 subarray (`[0]`).
- At second `0` → extends previous and adds new → 2 subarrays (`[0], [0,0]`).
- At third `0` → extends again → 3 subarrays (`[0], [0,0], [0,0,0]`).
Total = 6 subarrays.

Time Complexity:
-----------------
- O(n), since we traverse the array once.

Space Complexity:
------------------
- O(1), as we only use a few extra variables.
*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();          // length of the array
        long long cnt = 0;            // counts current streak of zeros
        long long ans = 0;            // stores the total count of zero-filled subarrays

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                cnt++;                // extend the zero streak
            } else {
                cnt = 0;              // reset if non-zero encountered
            }

            ans += cnt;               // add all subarrays ending at this index
        }

        return ans;                   // return total count
    }
};