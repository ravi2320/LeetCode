/*
2406. Divide Intervals Into Minimum Number of Groups
Solved
Medium
Topics
Companies
Hint
You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].

You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.

Return the minimum number of groups you need to make.

Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.

 

Example 1:

Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
Explanation: We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.
Example 2:

Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
Output: 1
Explanation: None of the intervals overlap, so we can put all of them in one group.
 

Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
1 <= lefti <= righti <= 106
*/

/*
Approach:
1. Sort the intervals by start time to process them in order.
2. Use a min-heap to track the end times of the current groups.
3. For each interval, if the smallest end time is less than the start of the interval, we can reuse that group.
4. Push the current interval's end time into the heap and continue.
5. The size of the heap at the end gives the minimum number of groups.

Time Complexity: O(n log n), due to sorting and heap operations.
Space Complexity: O(n), for the heap and storing intervals.
*/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Sort intervals based on their start times
        sort(intervals.begin(), intervals.end());

        // Min-heap to track the end times of current groups
        priority_queue<int, vector<int>, greater<int>> pq;

        // Process each interval
        for(auto &interval : intervals) {
            // If the smallest end time in the heap is less than the start of the current interval,
            // pop it because the current interval can be part of the same group.
            if(!pq.empty() && pq.top() < interval[0]) {
                pq.pop();
            }
            
            // Push the end time of the current interval into the heap
            pq.push(interval[1]);
        }

        // The size of the heap is the number of groups required
        return pq.size();
    }
};
