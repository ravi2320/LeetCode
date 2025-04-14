/*
1534. Count Good Triplets
Solved
Easy
Topics
Companies
Hint
Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.

A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

0 <= i < j < k < arr.length
|arr[i] - arr[j]| <= a
|arr[j] - arr[k]| <= b
|arr[i] - arr[k]| <= c
Where |x| denotes the absolute value of x.

Return the number of good triplets.

 

Example 1:

Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
Output: 4
Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
Example 2:

Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
Output: 0
Explanation: No triplet satisfies all conditions.
 

Constraints:

3 <= arr.length <= 100
0 <= arr[i] <= 1000
0 <= a, b, c <= 1000
*/

/*
Intuition:
----------
We are given a list of integers and three threshold values a, b, and c. 
We need to count the number of triplets (i, j, k) such that:
- 0 <= i < j < k < arr.length
- |arr[i] - arr[j]| <= a
- |arr[j] - arr[k]| <= b
- |arr[i] - arr[k]| <= c

Approach:
---------
- Use a brute-force approach with three nested loops to generate all valid triplets (i, j, k).
- For each triplet, check all three conditions.
- If all are satisfied, increment the count.

Time Complexity:
----------------
O(N^3), where N is the number of elements in the array.
Three nested loops each depend on N.

Space Complexity:
-----------------
O(1), as we use only a few integer variables for counting and indexing.
*/

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int cnt = 0;

        for(int i = 0; i <= n - 3; i++) {
            for(int j = i + 1; j <= n - 2; j++) {

                if(abs(arr[i] - arr[j]) <= a) {

                    for(int k = j + 1; k <= n - 1; k++) {
                        if(abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                            cnt++;
                        }
                    }
                }
            }
        }

        return cnt;
    }
};
