/*
1331. Rank Transform of an Array
Solved
Easy
Topics
Companies
Hint
Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.
 

Example 1:

Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
Example 2:

Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.
Example 3:

Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]
 

Constraints:

0 <= arr.length <= 105
-109 <= arr[i] <= 109
*/

/*
 * Approach:
 * - We need to transform the array such that each element is replaced by its rank in the sorted array.
 * - The approach first extracts the unique elements of the array, sorts them, and then assigns ranks starting from 1.
 * - Finally, we replace each element in the original array with its corresponding rank.
 *
 * Time Complexity:
 * - O(n log n), where n is the number of elements in the input array.
 * - The main cost is sorting the unique elements (which is O(n log n) due to the sorting step).
 * - We also go through the original array twice: once to create a set (O(n)) and once to generate the result (O(n)).
 *
 * Space Complexity:
 * - O(n), where n is the number of elements in the input array.
 * - We use extra space for the set of unique elements and a map to store their ranks.
 */

class Solution {
public:
    // Function to transform the array into its rank-based representation
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Step 1: Insert all elements into a set to remove duplicates and sort them
        set<int> st(arr.begin(), arr.end());

        // Step 2: Map each unique element to its rank (1-based index)
        unordered_map<int, int> mp;
        int idx = 1;
        for(auto &itr : st){
            mp[itr] = idx++;  // Assign rank starting from 1
        }

        // Step 3: Replace each element in the original array with its rank
        vector<int> res;
        for(auto &x : arr){
            res.push_back(mp[x]);  // Get the rank from the map
        }

        return res;  // Return the ranked array
    }
};
