/*
826. Most Profit Assigning Work
Solved
Medium
Topics
Companies
You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
Return the maximum profit we can achieve after assigning the workers to the jobs.

 

Example 1:

Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
Example 2:

Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
Output: 0
 

Constraints:

n == difficulty.length
n == profit.length
m == worker.length
1 <= n, m <= 104
1 <= difficulty[i], profit[i], worker[i] <= 105
*/


/*
Intuition:
- Each worker should be assigned the most profitable job they can handle.
- Sort both workers and jobs based on difficulty.
- Use a priority queue to keep track of the highest profits available up to the current worker's capability.

Approach:
1. Combine the difficulty and profit arrays into a vector of pairs and sort it based on difficulty.
2. Sort the worker array.
3. Use a priority queue to maintain the highest available profit for the current worker.
4. Iterate through each worker, and for each worker, push the profits of all jobs they can handle into the priority queue.
5. Add the maximum profit available (top of the priority queue) to the total profit for each worker.

Time Complexity:
- Sorting the worker array: O(m log m), where m is the number of workers.
- Sorting the jobs based on difficulty: O(n log n), where n is the number of jobs.
- Iterating through workers and maintaining the priority queue: O(m + n log n).

Space Complexity:
- O(n) for storing the jobs in a vector of pairs.
- O(n) for the priority queue in the worst case.

*/

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        
        // Pairing difficulty and profit and sorting them by difficulty
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        
        // Sorting worker array
        sort(worker.begin(), worker.end());
        
        // Max heap to keep track of the maximum profit for the current difficulty
        priority_queue<int> pq;
        int j = 0;
        int totalProfit = 0;

        // Iterate through each worker
        for (int i = 0; i < m; ++i) {
            // Push all jobs that the current worker can do into the priority queue
            while (j < n && jobs[j].first <= worker[i]) {
                pq.push(jobs[j].second);
                ++j;
            }
            // If there are jobs the worker can do, add the max profit available to the total profit
            if (!pq.empty()) {
                totalProfit += pq.top();
            }
        }

        return totalProfit;
    }
};

/*
Intuition:
- Each worker should be assigned the most profitable job they can handle.
- Sort both workers and jobs based on difficulty.
- Iterate through the workers and for each worker, update the maximum profit they can achieve.

Approach:
1. Combine the difficulty and profit arrays into a vector of pairs and sort it based on difficulty.
2. Sort the worker array.
3. Iterate through each worker, and for each worker, update the maximum profit they can achieve from the jobs available up to their capability.

Time Complexity:
- Sorting the worker array: O(m log m), where m is the number of workers.
- Sorting the jobs based on difficulty: O(n log n), where n is the number of jobs.
- Iterating through workers and jobs: O(m + n).

Space Complexity:
- O(n) for storing the jobs in a vector of pairs.

*/

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        vector<pair<int, int>> jobs(n);

        // Pairing difficulty and profit
        for (int i = 0; i < n; ++i) {
            jobs[i] = {difficulty[i], profit[i]};
        }

        // Sorting jobs by difficulty and workers by capability
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int max_profit = 0, ans = 0, j = 0;

        // Iterate through each worker
        for (int i = 0; i < worker.size(); ++i) {
            // Update the maximum profit up to the current worker's capability
            while (j < n && jobs[j].first <= worker[i]) {
                max_profit = max(max_profit, jobs[j].second);
                ++j;
            }
            ans += max_profit;
        }

        return ans;
    }
};

