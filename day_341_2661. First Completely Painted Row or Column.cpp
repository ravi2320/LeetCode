/*
2661. First Completely Painted Row or Column
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely painted in mat.

 

Example 1:

image explanation for example 1
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
Example 2:

image explanation for example 2
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].
 

Constraints:

m == mat.length
n = mat[i].length
arr.length == m * n
1 <= m, n <= 105
1 <= m * n <= 105
1 <= arr[i], mat[r][c] <= m * n
All the integers of arr are unique.
All the integers of mat are unique.
*/

/*
Approach:
1. Create a hash map to store the position (row, column) of each element in the matrix.
2. Use arrays to track the count of marked cells in each row and column.
3. Iterate through the input array, mark corresponding cells, and check if a row or column is completely marked.

Time Complexity: O(m * n + k)
- O(m * n) to map all elements of the matrix.
- O(k) to process the input array.

Space Complexity: O(m + n + m * n)
- O(m * n) for the hash map.
- O(m + n) for row and column counters.
*/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        // Map to store the position of each element in the matrix
        unordered_map<int, pair<int, int>> positionMap;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                positionMap[mat[i][j]] = {i, j};
            }
        }

        // Arrays to track the number of marked cells in each row and column
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        // Process the input array
        for (int idx = 0; idx < arr.size(); idx++) {
            int element = arr[idx];
            auto [i, j] = positionMap[element];

            // Increment the count for the row and column
            rowCount[i]++;
            colCount[j]++;

            // Check if the current row or column is fully marked
            if (rowCount[i] == n || colCount[j] == m) {
                return idx;
            }
        }

        // If no row or column is completely marked, return -1
        return -1;
    }
};

/*
Approach:
1. Create a hash map to store the indices of elements in the array `arr`.
2. For each row, calculate the maximum index of its elements in `arr`.
3. For each column, calculate the maximum index of its elements in `arr`.
4. Track the minimum of these maximum indices across all rows and columns.

Time Complexity: O(m * n)
- Building the hash map: O(arr.size())
- Iterating over rows and columns: O(m * n)

Space Complexity: O(m * n)
- Hash map storage: O(m * n)
*/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, int> mp;

        // Map values of arr to their indices
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }

        int minIndex = INT_MAX;

        // Check for row completion
        for (int row = 0; row < m; row++) {
            int lastIndex = INT_MIN;

            for (int col = 0; col < n; col++) {
                int val = mat[row][col];
                lastIndex = max(lastIndex, mp[val]);
            }

            // Update the minimum index
            minIndex = min(minIndex, lastIndex);
        }

        // Check for column completion
        for (int col = 0; col < n; col++) {
            int lastIndex = INT_MIN;

            for (int row = 0; row < m; row++) {
                int val = mat[row][col];
                lastIndex = max(lastIndex, mp[val]);
            }

            // Update the minimum index
            minIndex = min(minIndex, lastIndex);
        }

        return minIndex;
    }
};