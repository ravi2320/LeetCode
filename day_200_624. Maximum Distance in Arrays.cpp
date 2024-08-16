/*
624. Maximum Distance in Arrays
Solved
Medium
Topics
Companies
You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

 

Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Example 2:

Input: arrays = [[1],[1]]
Output: 0
 

Constraints:

m == arrays.length
2 <= m <= 105
1 <= arrays[i].length <= 500
-104 <= arrays[i][j] <= 104
arrays[i] is sorted in ascending order.
There will be at most 105 integers in all the arrays.
*/

/*
Intuition:
- The problem is about finding the maximum distance between elements from different arrays where the distance is defined as the absolute difference between two elements.
- We can solve this by maintaining the minimum and maximum elements encountered so far while iterating through the arrays. This helps in calculating potential maximum distances without comparing each element in every array to each element in every other array.

Time Complexity:
- The time complexity is O(n), where n is the number of arrays. We iterate through each array exactly once.

Space Complexity:
- The space complexity is O(1) as we only use a few extra variables for storing the current minimum, maximum, and result.

Approach:
1. Initialize the minimum (`MIN`) and maximum (`MAX`) values with the first array's first and last elements respectively.
2. Iterate through the rest of the arrays:
   - Calculate the possible maximum distance using the current array's first and last elements with the `MAX` and `MIN` values.
   - Update the result with the maximum of the calculated distances.
   - Update `MIN` and `MAX` with the current array's first and last elements, respectively.
3. Return the maximum distance found.

*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        
        // Initialize MIN and MAX with the first array's elements
        int MIN = arrays[0].front();
        int MAX = arrays[0].back();
        int result = 0;

        // Traverse through the remaining arrays
        for (int i = 1; i < n; i++) {
            // Calculate the maximum possible distance with the current array's first and last elements
            result = max(result, max(abs(MAX - arrays[i].front()), abs(arrays[i].back() - MIN)));

            // Update MAX and MIN with the current array's last and first elements respectively
            MAX = max(MAX, arrays[i].back());
            MIN = min(MIN, arrays[i].front());
        }

        // Return the maximum distance found
        return result;
    }
};
