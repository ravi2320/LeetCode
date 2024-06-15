/*
502. IPO
Solved
Hard
Topics
Companies
Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.

 

Example 1:

Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
Example 2:

Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
Output: 6
 

Constraints:

1 <= k <= 105
0 <= w <= 109
n == profits.length
n == capital.length
1 <= n <= 105
0 <= profits[i] <= 104
0 <= capital[i] <= 109
*/

/*
Intuition:
- The problem is about maximizing the capital by selecting up to `k` projects.
- Each project has a profit and a capital requirement.
- We want to always select the most profitable project that we can afford with our current capital.

Approach:
1. Pair up each project's capital requirement with its profit.
2. Sort the projects based on their capital requirements in ascending order.
3. Use a max-heap (priority queue) to always select the project with the highest profit that we can afford.
4. Iterate through the projects and use the max-heap to keep track of the most profitable projects available with the current capital.

Steps:
1. Create a vector of pairs where each pair consists of the capital requirement and the profit of a project.
2. Sort this vector based on the capital requirement.
3. Use a priority queue (max-heap) to store the profits of the projects we can currently afford.
4. Iterate up to `k` times, each time:
   - Add all projects to the heap whose capital requirement is less than or equal to the current capital.
   - If the heap is not empty, select the project with the highest profit (top of the heap) and add its profit to the current capital.
   - If the heap is empty, break out of the loop as we can't afford any more projects.

Time Complexity:
- O(n log n) for sorting the projects based on capital requirements.
- O(k log n) for pushing and popping elements from the heap, where in the worst case, we perform up to `k` operations and each operation takes O(log n) time.
- Overall, O(n log n + k log n).

Space Complexity:
- O(n) for the vector of pairs and the heap.

*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = profits.size();

        // Pair up each project's capital requirement with its profit
        vector<pair<int, int>> vec(n);

        for(int i = 0; i < n; i++){
            vec[i] = {capital[i], profits[i]};
        }

        // Sort the projects based on capital requirements
        sort(vec.begin(), vec.end());

        // Max-heap to keep track of the most profitable projects available with the current capital
        priority_queue<int> pq;

        int i = 0;
        while(k--) {

            // Add all projects to the heap whose capital requirement is less than or equal to the current capital
            while(i < n && vec[i].first <= w){
                pq.push(vec[i].second);
                i++;
            }

            // If the heap is empty, break out of the loop as we can't afford any more projects
            if(pq.empty())
                break;

            // Select the project with the highest profit and add its profit to the current capital
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};
