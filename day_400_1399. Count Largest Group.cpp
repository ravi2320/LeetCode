/*
1399. Count Largest Group
Solved
Easy
Topics
Companies
Hint
You are given an integer n.

Each number from 1 to n is grouped according to the sum of its digits.

Return the number of groups that have the largest size.

 

Example 1:

Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
There are 4 groups with largest size.
Example 2:

Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.
 

Constraints:

1 <= n <= 104
*/

/*
Intuition:
Group all numbers from 1 to n based on the sum of their digits. For example, 12 and 21 both belong to group 3 (1+2).
Then, identify the group(s) with the largest size and return the number of such groups.

Approach:
1. Iterate from 1 to n.
2. For each number, calculate its digit sum and increment its corresponding frequency in a hash map.
3. Track the maximum group size (`maxi`) and how many groups have that size (`cnt`).

Time Complexity: O(N * log N)
- We loop through numbers from 1 to n. For each number, digitSum runs in O(log(num)), which is O(log N).
- So, overall time is O(N log N).

Space Complexity: O(N)
- In the worst case, we may have up to N different digit sums (though realistically it's around log-scaled values).
*/

class Solution {
public:
    // Helper function to calculate digit sum of a number
    int digitSum(int num) {
        int sum = 0;
        while (num) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> mp; // Maps digit sum to frequency
        int maxi = 0;               // Maximum size of any group
        int cnt = 0;                // Count of groups with maximum size

        for (int i = 1; i <= n; i++) {
            int sum = digitSum(i);
            mp[sum]++;

            if (mp[sum] == maxi) {
                cnt++; // Another group with the same max size
            } else if (mp[sum] > maxi) {
                maxi = mp[sum]; // New maximum size
                cnt = 1;        // Reset count for this new max group
            }
        }

        return cnt;
    }
};