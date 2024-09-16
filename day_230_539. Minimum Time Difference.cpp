/*
539. Minimum Time Difference
Solved
Medium
Topics
Companies
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 

Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".
*/

/*
Approach:
1. Convert each time point from "HH:MM" format into the total number of minutes since midnight.
   - For each time, the total minutes can be calculated as: `hours * 60 + minutes`.
2. Sort the array of minute values.
3. Calculate the minimum difference between consecutive time points in the sorted array.
4. Additionally, calculate the time difference between the last and the first time points, considering the circular nature of the clock (i.e., the time after midnight).
5. Return the minimum of all the differences.

Time Complexity:
- O(n log n): The primary cost comes from sorting the `n` time points. The conversion of each time point to minutes takes O(n), and the calculation of differences takes O(n).

Space Complexity:
- O(n): We use an additional vector `minutes` of size `n` to store the minute representation of each time point.

*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n, 0);  // Vector to store time in minutes format

        // Convert time points to minutes
        for (int i = 0; i < n; i++) {
            minutes[i] = stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3));  // Convert "HH:MM" to total minutes
        }

        // Sort the time points in ascending order of minutes
        sort(minutes.begin(), minutes.end());

        int res = INT_MAX;  // Initialize result to maximum possible difference

        // Find the minimum difference between consecutive time points
        for (int i = 1; i < n; i++) {
            res = min(res, minutes[i] - minutes[i - 1]);  // Difference between adjacent times
        }

        // Handle the circular case (difference between the last and the first time point)
        return min(res, (24 * 60 - minutes[n - 1]) + minutes[0]);  // Compare with circular difference
    }
};
