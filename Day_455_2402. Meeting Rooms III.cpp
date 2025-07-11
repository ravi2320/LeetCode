/*
2402. Meeting Rooms III
Solved

avatar
Discuss Approach
arrow-up
Hard
Topics
premium lock icon
Companies
Hint
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.

 

Example 1:

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0. 
Example 2:

Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 
 

Constraints:

1 <= n <= 100
1 <= meetings.length <= 105
meetings[i].length == 2
0 <= starti < endi <= 5 * 105
All the values of starti are unique.
*/

/*
Approach:
- We are simulating room assignments for a sequence of meetings using two vectors:
  1. `times[i]` represents the next free time of room i.
  2. `ans[i]` represents how many times room i has been used.

- For each meeting:
  - Try to assign it to the earliest available room (whose available time ≤ start of the meeting).
  - If no room is available at the meeting's start time, assign the meeting to the room that becomes available the earliest.
    In that case, delay the meeting and update its new end time accordingly.

- After assigning all meetings, return the room with the **maximum usage count** (`ans[i]`).
  In case of tie, return the room with the smallest index.

Intuition:
- This greedy simulation ensures that meetings are scheduled as early as possible,
  while also respecting room availability. It's a variation of the classical room scheduling problem.

Time Complexity:
- O(m * n), where m = number of meetings and n = number of rooms

Space Complexity:
- O(n), for `times` and `ans` arrays
*/

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        vector<int> ans(n, 0);             // Count of meetings for each room
        vector<long long> times(n, 0);     // When each room becomes free
        bool isMeetingStarted = false;

        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        for (int i = 0; i < m; i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            isMeetingStarted = false;
            long long earliestTime = LLONG_MAX;
            int earliestRoom = -1;

            for (int j = 0; j < n; j++) {
                // Track earliest available room if all are busy
                if (times[j] < earliestTime) {
                    earliestTime = times[j];
                    earliestRoom = j;
                }

                // If room j is free at meeting start time, assign it
                if (times[j] <= start) {
                    times[j] = end;
                    ans[j]++;
                    isMeetingStarted = true;
                    break;
                }
            }

            // If no room is free, assign it to the earliest available room
            if (!isMeetingStarted) {
                times[earliestRoom] += (end - start); // Delay meeting
                ans[earliestRoom]++;
            }
        }

        // Find the room with the maximum meetings
        int maxMeetings = -1;
        int resultRoom = -1;
        for (int i = 0; i < n; i++) {
            if (ans[i] > maxMeetings) {
                maxMeetings = ans[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};
