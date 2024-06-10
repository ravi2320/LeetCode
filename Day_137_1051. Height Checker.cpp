/*
1051. Height Checker
Solved
Easy
Topics
Companies
Hint
A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.

You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

Return the number of indices where heights[i] != expected[i].

 

Example 1:

Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation: 
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.
Example 2:

Input: heights = [5,1,2,3,4]
Output: 5
Explanation:
heights:  [5,1,2,3,4]
expected: [1,2,3,4,5]
All indices do not match.
Example 3:

Input: heights = [1,2,3,4,5]
Output: 0
Explanation:
heights:  [1,2,3,4,5]
expected: [1,2,3,4,5]
All indices match.
 

Constraints:

1 <= heights.length <= 100
1 <= heights[i] <= 100
*/

/*
Intuition:
- The problem is to find how many elements are out of place if the array were sorted.
- The idea is to compare the original array with its sorted version and count the mismatches.

Approach:
1. Create a copy of the original array.
2. Sort the copy.
3. Iterate through both arrays and compare each element at the same index.
4. Count the number of indices where the elements in the original array differ from the sorted array.

Time Complexity: O(n log n)
- Sorting the array takes O(n log n) time.
- Comparing the elements of the two arrays takes O(n) time.

Space Complexity: O(n)
- We use extra space to store a copy of the original array, resulting in O(n) space complexity.
*/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // Create a copy of the original array and sort it
        vector<int> sortedHeights(heights.begin(), heights.end());
        sort(sortedHeights.begin(), sortedHeights.end());
        
        int count = 0;
        // Compare each element of the original and sorted arrays
        for(int i = 0; i < heights.size(); i++) {
            if(heights[i] != sortedHeights[i])
                count++;
        }
        
        return count;
    }
};
