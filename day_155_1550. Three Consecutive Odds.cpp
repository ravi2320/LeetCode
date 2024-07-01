/*
1550. Three Consecutive Odds
Solved
Easy
Topics
Companies
Hint
Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
 

Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.
Example 2:

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.
 

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
*/

// Intuition:
// The problem is to determine if there are three consecutive odd numbers in the array. The approach involves iterating through the array and checking if any three consecutive elements are all odd. This can be done efficiently by checking each element and the next two elements in a single pass through the array.

// Time Complexity: O(n), where n is the number of elements in the array. Each element is checked once.
// Space Complexity: O(1), as we are using only a constant amount of extra space.

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size(); // Get the size of the array.

        // Iterate through the array, stopping 2 elements before the end to avoid out-of-bound errors.
        for(int i = 0; i < n - 2; i++) {
            // Check if the current element and the next two elements are all odd.
            if(arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1)
                return true; // If they are, return true.
        }

        return false; // If no such triplet is found, return false.
    }
};
