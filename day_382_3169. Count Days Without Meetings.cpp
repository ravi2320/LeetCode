/*
3169. Count Days Without Meetings
Solved
Medium
Topics
Companies
Hint
You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.

 

Example 1:

Input: days = 10, meetings = [[5,7],[1,3],[9,10]]

Output: 2

Explanation:

There is no meeting scheduled on the 4th and 8th days.

Example 2:

Input: days = 5, meetings = [[2,4],[1,3]]

Output: 1

Explanation:

There is no meeting scheduled on the 5th day.

Example 3:

Input: days = 6, meetings = [[1,6]]

Output: 0

Explanation:

Meetings are scheduled for all working days.

 

Constraints:

1 <= days <= 109
1 <= meetings.length <= 105
meetings[i].length == 2
1 <= meetings[i][0] <= meetings[i][1] <= days
*/

/*
    Approach:
    - Sort the meetings based on their start day.
    - Traverse the sorted meetings:
        - If there's a gap between the current meeting's start day and the end of the last meeting, add the gap to the result.
        - Keep updating the latest `end` day.
    - After processing all meetings, if there are days left after the last meeting, count those as well.

    Intuition:
    - By sorting and greedily merging/processing intervals, we can efficiently find the gaps (free days).

    Time Complexity: O(N log N) due to sorting.
    Space Complexity: O(1) extra space.
*/

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end()); // Sort meetings by start day

        int start = 0, end = 0, res = 0;

        for (auto &meet : meetings) {
            // If there's a gap between previous meeting end and current meeting start
            if (meet[0] > end) {
                res += meet[0] - end - 1; // Count free days in the gap
            }
            end = max(end, meet[1]); // Update end day to max so far
        }

        // Count any remaining free days after last meeting
        if (days > end) {
            res += days - end;
        }

        return res;
    }
};