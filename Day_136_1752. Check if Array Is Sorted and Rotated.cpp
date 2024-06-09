/*
1752. Check if Array Is Sorted and Rotated
Solved
Easy
Topics
Companies
Hint
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

/*
Intuition:
- The task is to check if the array can be sorted in non-decreasing order by rotating it.
- This can be done by checking how many times the order of the array breaks (i.e., an element is greater than the next element).
- If the array can be sorted by a single rotation, there should be at most one such break point.

Approach:
1. Initialize a counter `cnt` to count the number of times an element is greater than the next element.
2. Iterate through the array and increment the counter whenever a break point is found.
3. Additionally, check if the last element is greater than the first element (as it would also indicate a break if we consider the array to be circular).
4. If the count of break points is less than or equal to 1, the array can be sorted by rotating it.

Time Complexity: O(n)
- The algorithm performs a single pass through the array, making it linear in time complexity.

Space Complexity: O(1)
- The algorithm uses a constant amount of extra space.

*/

class Solution {
public:
    bool check(vector<int>& arr) {
        int cnt = 0;
        int n = arr.size();
        
        // Count the number of break points in the array
        for(int i = 0; i < n - 1; i++) {
            if(arr[i] > arr[i + 1])
                cnt++;
        }
        
        // Check the circular break point
        if(arr[n - 1] > arr[0])
            cnt++;
            
        // If there is at most one break point, return true
        return cnt <= 1;
    }
};
