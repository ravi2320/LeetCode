/*
1235. Maximum Profit in Job Scheduling
Solved
Hard
Topics
Companies
Hint
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

Example 1:



Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:



Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
Example 3:



Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
 

Constraints:

1 <= startTime.length == endTime.length == profit.length <= 5 * 104
1 <= startTime[i] < endTime[i] <= 109
1 <= profit[i] <= 104
*/

class Solution {
private:
    class Job {
    public:
        int StartTime, EndTime, Profit;
        Job(int st, int et, int pr) : StartTime(st), EndTime(et), Profit(pr) {}
    };

public:
    int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
        std::vector<Job> jobs;
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            Job j(startTime[i], endTime[i], profit[i]);
            jobs.push_back(j);
        }

        std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.EndTime < b.EndTime;
        });

        std::map<int, int> dp; // Use dynamic programming to store max profit for each ending time
        dp[0] = 0; // Base case

        for (const Job& j : jobs) {
            auto it = dp.upper_bound(j.StartTime); // Find the job with the nearest end time
            --it; // Move back to the previous job

            int maxProfitTillStartTime = it->second;
            int totalProfit = maxProfitTillStartTime + j.Profit;

            int maxProfit = dp.rbegin()->second; // Get the maximum profit until now

            if (totalProfit > maxProfit) {
                dp[j.EndTime] = totalProfit; // Update the dp table
            }
        }

        return dp.rbegin()->second; // Return the maximum profit
    }
};