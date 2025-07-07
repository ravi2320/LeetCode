/*
1353. Maximum Number of Events That Can Be Attended
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

Return the maximum number of events you can attend.

 

Example 1:


Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
Example 2:

Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
 

Constraints:

1 <= events.length <= 105
events[i].length == 2
1 <= startDayi <= endDayi <= 105
*/

/*
Approach:
- Each event is represented by a pair [startDay, endDay].
- We aim to attend as many events as possible, where only one event can be attended per day.
- Sort all events by start day.
- Use a min-heap (priority queue) to store end days of ongoing events.
- For each day, push all events that start that day into the heap.
- Attend the event that ends the earliest (i.e., top of min-heap).
- Remove expired events (whose end day < current day).
- Repeat until all events are processed or heap is empty.

Intuition:
- Attend events that are going to end soonest (greedy approach).
- Using a min-heap helps efficiently track the event that will end earliest.

Time Complexity:
- O(N log N + D log N), where:
  - N = number of events
  - D = range of days we need to process
- Sorting events takes O(N log N).
- Each event is inserted and removed from the heap once → O(N log N) heap operations.

Space Complexity:
- O(N) for the heap and sorted event storage.
*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();

        // Sort events based on start day
        sort(events.begin(), events.end());

        // Min-heap to keep track of end days of active events
        priority_queue<int, vector<int>, greater<int>> pq;

        int day = events[0][0];  // Start from the first event's start day
        int cnt = 0;  // Count of events attended
        int i = 0;    // Pointer to events

        while (!pq.empty() || i < n) {
            // If no ongoing events, fast forward to the next event's start day
            if (pq.empty()) {
                day = events[i][0];
            }

            // Add all events starting on the current day
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);  // Store the end day
                i++;
            }

            // Attend the event with the earliest end day
            if (!pq.empty()) {
                pq.pop();
                cnt++;
            }

            // Remove all events from the heap that have already expired
            while (!pq.empty() && pq.top() < day + 1) {
                pq.pop();
            }

            day++;  // Move to the next day
        }

        return cnt;
    }
};