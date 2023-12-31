/*
1074. Number of Submatrices That Sum to Target
Solved
Hard
Topics
Companies
Hint
Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

 

Example 1:


Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
Example 3:

Input: matrix = [[904]], target = 0
Output: 0
 

Constraints:

1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8
*/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++)
            for(int j=1; j<n; j++)
                matrix[i][j] += matrix[i][j-1];

        int answer = 0;
        for(int start = 0; start<n; start++)
        {
            for(int end = start; end<n; end++)
            {
                unordered_map<int, int> hash;
                hash[0] = 1;

                int sum = 0;
                for(int row = 0; row<m; row++)
                {
                    sum += matrix[row][end] - (start > 0 ? matrix[row][start-1] : 0);
                    if(hash.find(sum-target) != hash.end())
                        answer += hash[sum - target];

                    hash[sum]++;
                }
            }
        }
        return answer;
    }
};