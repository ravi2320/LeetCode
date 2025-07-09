/*
3439. Reschedule Meetings for Maximum Free Time I

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer eventTime denoting the duration of an event, where the event occurs from time t = 0 to time t = eventTime.

You are also given two integer arrays startTime and endTime, each of length n. These represent the start and end time of n non-overlapping meetings, where the ith meeting occurs during the time [startTime[i], endTime[i]].

You can reschedule at most k meetings by moving their start time while maintaining the same duration, to maximize the longest continuous period of free time during the event.

The relative order of all the meetings should stay the same and they should remain non-overlapping.

Return the maximum amount of free time possible after rearranging the meetings.

Note that the meetings can not be rescheduled to a time outside the event.

 

Example 1:

Input: eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]

Output: 2

Explanation:



Reschedule the meeting at [1, 2] to [2, 3], leaving no meetings during the time [0, 2].

Example 2:

Input: eventTime = 10, k = 1, startTime = [0,2,9], endTime = [1,4,10]

Output: 6

Explanation:



Reschedule the meeting at [2, 4] to [1, 3], leaving no meetings during the time [3, 9].

Example 3:

Input: eventTime = 5, k = 2, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]

Output: 0

Explanation:

There is no time during the event not occupied by meetings.

 

Constraints:

1 <= eventTime <= 109
n == startTime.length == endTime.length
2 <= n <= 105
1 <= k <= n
0 <= startTime[i] < endTime[i] <= eventTime
endTime[i] <= startTime[i + 1] where i lies in the range [0, n - 2].
*/

/*
Approach:
- We are given an array of start and end times for events in a day.
- The goal is to find the **maximum total free time** from **at most (k + 1)** free periods between events,
  such that their combined length is maximized and they do not overlap with event periods.

Steps:
1. Calculate all the free time gaps between:
   - The start of the day and the first event.
   - Between consecutive events.
   - The end of the last event and the end of the day (`eventTime`).
2. Use a sliding window of size at most (k + 1) to find the window of free times that yields the maximum sum.

Intuition:
- There are `n + 1` possible free intervals for `n` events.
- We are allowed to "select" up to (k + 1) free intervals that are **contiguous**.
- So we slide a window of at most (k + 1) intervals and track the maximum total free time.

Time Complexity: O(n)
- We iterate through the event list and the sliding window once.

Space Complexity: O(n)
- For storing the free time intervals.
*/

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTime;

        // Gap before the first event (if any)
        if(startTime[0] > 0){
            freeTime.push_back(startTime[0]);
        }

        // Gaps between consecutive events
        for(int i = 1; i < n; i++){
            freeTime.push_back(startTime[i] - endTime[i - 1]);
        }

        // Gap after the last event (if any)
        if(endTime[n - 1] < eventTime){
            freeTime.push_back(eventTime - endTime[n - 1]);
        }

        // Sliding window to find the max sum of (k + 1) contiguous gaps
        int maxFreeTime = 0, currentSum = 0;
        int m = freeTime.size();
        int i = 0, j = 0;

        while(j < m){
            currentSum += freeTime[j];

            // If window size exceeds k+1, slide the window
            while(j - i + 1 > k + 1){
                currentSum -= freeTime[i];
                i++;
            }

            maxFreeTime = max(maxFreeTime, currentSum);
            j++;
        }

        return maxFreeTime;
    }
};
