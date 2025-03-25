/*
3394. Check if Grid can be Cut into Sections
Solved
Medium
Topics
Companies
Hint
You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:

(startx, starty): The bottom-left corner of the rectangle.
(endx, endy): The top-right corner of the rectangle.
Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:

Each of the three resulting sections formed by the cuts contains at least one rectangle.
Every rectangle belongs to exactly one section.
Return true if such cuts can be made; otherwise, return false.

 

Example 1:

Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]

Output: true

Explanation:



The grid is shown in the diagram. We can make horizontal cuts at y = 2 and y = 4. Hence, output is true.

Example 2:

Input: n = 4, rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]

Output: true

Explanation:



We can make vertical cuts at x = 2 and x = 3. Hence, output is true.

Example 3:

Input: n = 4, rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]

Output: false

Explanation:

We cannot make two horizontal or two vertical cuts that satisfy the conditions. Hence, output is false.

 

Constraints:

3 <= n <= 109
3 <= rectangles.length <= 105
0 <= rectangles[i][0] < rectangles[i][2] <= n
0 <= rectangles[i][1] < rectangles[i][3] <= n
No two rectangles overlap.
*/

// Approach:
// 1. Extract all x-intervals and y-intervals from the given rectangles.
// 2. Sort the intervals based on their starting points.
// 3. Merge overlapping intervals to get the minimal non-overlapping segments.
// 4. If we have 3 or more non-overlapping segments in either x or y direction, return true; otherwise, return false.

// Intuition:
// - If we can divide the plane into at least 3 non-overlapping segments in either the x or y direction, we can guarantee a valid cut.
// - Merging overlapping intervals ensures that we correctly count the number of distinct segments.

// Time Complexity: O(N log N) 
//   -> Sorting the intervals takes O(N log N), and merging takes O(N).
// Space Complexity: O(N)
//   -> For storing the merged intervals.

class Solution {
public:
    // Function to merge overlapping intervals
    vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals) {
        vector<vector<int>> merged;
        
        for(auto &interval : intervals) {
            // If merged list is empty, simply add the current interval
            if(merged.empty()) {
                merged.push_back(interval);
            }
            // If current interval overlaps with the last merged interval, merge them
            else if(interval[0] <= merged.back()[1]) {
                merged.back()[0] = min(merged.back()[0], interval[0]);
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
            // Otherwise, push a new interval into merged list
            else {
                merged.push_back(interval);
            }
        }

        return merged;
    }

    // Function to check if valid cuts exist
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x_intervals, y_intervals;

        // Extract x and y intervals from the rectangles
        for(auto &rect : rectangles) {
            x_intervals.push_back({rect[0], rect[2]}); // {x_start, x_end}
            y_intervals.push_back({rect[1], rect[3]}); // {y_start, y_end}
        }

        // Sort intervals based on their start positions
        sort(x_intervals.begin(), x_intervals.end());

        // Merge overlapping x-intervals
        x_intervals = mergeIntervals(x_intervals);

        // If there are at least 3 non-overlapping x-segments, return true
        if(x_intervals.size() >= 3) {
            return true;
        }

        // Sort y-intervals
        sort(y_intervals.begin(), y_intervals.end());

        // Merge overlapping y-intervals
        y_intervals = mergeIntervals(y_intervals);

        // If there are at least 3 non-overlapping y-segments, return true
        return y_intervals.size() >= 3;
    }
};
