/*
2141. Maximum Running Time of N Computers

You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.

Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.

Note that the batteries cannot be recharged.

Return the maximum number of minutes you can run all the n computers simultaneously.

 

Example 1:


Input: n = 2, batteries = [3,3,3]
Output: 4
Explanation: 
Initially, insert battery 0 into the first computer and battery 1 into the second computer.
After two minutes, remove battery 1 from the second computer and insert battery 2 instead. Note that battery 1 can still run for one minute.
At the end of the third minute, battery 0 is drained, and you need to remove it from the first computer and insert battery 1 instead.
By the end of the fourth minute, battery 1 is also drained, and the first computer is no longer running.
We can run the two computers simultaneously for at most 4 minutes, so we return 4.

Example 2:


Input: n = 2, batteries = [1,1,1,1]
Output: 2
Explanation: 
Initially, insert battery 0 into the first computer and battery 2 into the second computer. 
After one minute, battery 0 and battery 2 are drained so you need to remove them and insert battery 1 into the first computer and battery 3 into the second computer. 
After another minute, battery 1 and battery 3 are also drained so the first and second computers are no longer running.
We can run the two computers simultaneously for at most 2 minutes, so we return 2.
 

Constraints:

1 <= n <= batteries.length <= 105
1 <= batteries[i] <= 109
*/

/*
Intuition:
-----------
We have `n` computers that must run simultaneously for the same duration `T`.
We have `batteries[]`, where each battery has a fixed capacity.  
Any battery can be used on any computer, and batteries can be swapped at any time.

To run n computers for T minutes, total required energy is:
        n * T

Since each battery contributes `min(battery, T)` usable capacity,
a duration T is possible if:
    sum(min(battery[i], T)) >= n * T     (Condition for feasibility)

The function is monotonic:
- If we can run T minutes, we can also run any time < T.
- If we cannot run T minutes, we cannot run any time > T.

Therefore, we use **Binary Search** on the answer.

Approach:
---------
1. Compute total available energy = sum(batteries).
2. The maximum possible running time:
        max_T = total_energy / n
3. Binary search T in range [0, max_T]
4. For each mid = T:
       Check if sum(min(battery[i], T)) ≥ n*T
5. Return the maximum feasible T.

Time Complexity:
----------------
O(m log(total/n))  
where m = number of batteries.

Space Complexity:
-----------------
O(1) extra space (ignoring large inputs).

*/

class Solution {
    typedef long long ll;
public:

    // Check if it's possible for n computers to run for 'mid' minutes
    bool possible(vector<int>& batteries, int n, ll mid) {

        ll required = mid * n;  // total energy required

        for (auto &battery : batteries) {

            // Each battery contributes at most `mid`
            required -= min((ll)battery, mid);

            // If requirement is fulfilled early, return true
            if (required <= 0)
                return true;
        }

        return required <= 0;
    }

    long long maxRunTime(int n, vector<int>& batteries) {

        // Lower bound: 0 minutes (or min element, but 0 is safer)
        ll l = 0;

        // Total energy of all batteries
        ll totalEnergy = accumulate(batteries.begin(), batteries.end(), 0LL);

        // Maximum possible time = total energy evenly divided
        ll r = totalEnergy / n;

        ll res = 0;   // best feasible answer

        // Binary search on running time
        while (l <= r) {
            ll mid = l + (r - l) / 2;

            if (possible(batteries, n, mid)) {
                res = mid;      // mid is feasible
                l = mid + 1;    // try for larger time
            }
            else {
                r = mid - 1;    // mid not possible → try smaller
            }
        }

        return res;
    }
};
