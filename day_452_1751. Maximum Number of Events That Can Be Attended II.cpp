/*
1751. Maximum Number of Events That Can Be Attended II
Solved

avatar
Discuss Approach
arrow-up
Hard
Topics
premium lock icon
Companies
Hint
You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return the maximum sum of values that you can receive by attending events.

 

Example 1:



Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
Example 2:



Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.
Example 3:



Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
Output: 9
Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.
 

Constraints:

1 <= k <= events.length
1 <= k * events.length <= 106
1 <= startDayi <= endDayi <= 109
1 <= valuei <= 106
*/

/*
Approach:
- Given a list of events where each event has a start time, end time, and value, select at most `k` non-overlapping events such that the total value is maximized.
- Use **Dynamic Programming + Binary Search**:
  - For each event at index `idx`, we have 2 choices:
    1. Skip the event → move to the next event (`idx + 1`)
    2. Take the event → add its value and jump to the next non-overlapping event using `upper_bound`
- Use memoization (`dp[idx][k]`) to store results of subproblems.
- Before solving, **sort** events by start time so binary search can be applied to find the next non-overlapping event.

Intuition:
- This is similar to the "Weighted Job Scheduling" problem.
- When we take an event, we need to find the **next event that starts after the current event ends**, which is done efficiently with `upper_bound`.

Time Complexity: O(n * k * log n)  
- For each of the `n * k` subproblems, we do a binary search in `O(log n)`.

Space Complexity: O(n * k)  
- For the memoization table `dp`.

*/

class Solution {
    int n;
    vector<vector<int>> dp;

public:
    // Helper function to solve recursively with memoization
    int solve(vector<vector<int>> &events, int idx, int k) {
        if (idx >= n || k == 0)
            return 0;

        if (dp[idx][k] != -1)
            return dp[idx][k];

        // Option 1: Skip current event
        int skip = solve(events, idx + 1, k);

        // Option 2: Take current event
        // Find the next event that starts after current event ends
        vector<int> nextEvent = {events[idx][1], INT_MAX, INT_MAX};  // end_time of current
        int nextIdx = upper_bound(events.begin() + idx, events.end(), nextEvent) - events.begin();

        int take = events[idx][2] + solve(events, nextIdx, k - 1);

        // Store and return max of skip and take
        return dp[idx][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        dp.assign(n + 1, vector<int>(k + 1, -1));

        // Sort events based on start time (implicitly because upper_bound is based on this)
        sort(events.begin(), events.end());

        return solve(events, 0, k);
    }
};


/*
Approach:
- We use Bottom-Up Dynamic Programming (Tabulation) with Binary Search to efficiently solve the problem.
- First, sort the events based on start time.
- Let dp[i][j] represent the maximum value we can obtain from the i-th event to the end of the list, with j selections allowed.
- For each event at index i, we have two choices:
    1. Skip the event → value is dp[i+1][j]
    2. Take the event → add its value + dp[next][j-1], where `next` is the index of the first event starting after current event's end.

- To find the next event quickly, we use `upper_bound` on the list of start times.

Intuition:
- We are trying to pick at most `k` non-overlapping events such that their total value is maximized.
- By working backwards and precomputing values using DP, we avoid redundant recalculations.

Time Complexity: O(n * k * log n)
- O(n log n) to sort the events.
- O(n * k) iterations in the DP.
- Each DP transition involves a binary search in O(log n).

Space Complexity: O(n * k)
- DP table of size (n+1) x (k+1)
- O(n) additional space for storing start times.
*/

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();

        // Step 1: Sort events by start time
        sort(events.begin(), events.end());

        // Step 2: Prepare DP table and a list of start times for binary search
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        vector<int> startTimes(n);
        for (int i = 0; i < n; ++i) {
            startTimes[i] = events[i][0];
        }

        // Step 3: Fill the DP table from the back
        for (int i = n - 1; i >= 0; --i) {
            // Find the next event that starts after the current one ends
            int next = upper_bound(startTimes.begin(), startTimes.end(), events[i][1]) - startTimes.begin();

            for (int j = 1; j <= k; ++j) {
                // Option 1: Skip the current event
                dp[i][j] = dp[i + 1][j];

                // Option 2: Take the current event and add its value
                dp[i][j] = max(dp[i][j], events[i][2] + dp[next][j - 1]);
            }
        }

        // Final answer: Max value by starting at index 0 with k picks
        return dp[0][k];
    }
};
