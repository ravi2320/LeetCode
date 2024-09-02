/*
1894. Find the Student that Will Replace the Chalk
Solved
Medium
Topics
Companies
Hint
There are n students in a class numbered from 0 to n - 1. The teacher will give each student a problem starting with the student number 0, then the student number 1, and so on until the teacher reaches the student number n - 1. After that, the teacher will restart the process, starting with the student number 0 again.

You are given a 0-indexed integer array chalk and an integer k. There are initially k pieces of chalk. When the student number i is given a problem to solve, they will use chalk[i] pieces of chalk to solve that problem. However, if the current number of chalk pieces is strictly less than chalk[i], then the student number i will be asked to replace the chalk.

Return the index of the student that will replace the chalk pieces.

 

Example 1:

Input: chalk = [5,1,5], k = 22
Output: 0
Explanation: The students go in turns as follows:
- Student number 0 uses 5 chalk, so k = 17.
- Student number 1 uses 1 chalk, so k = 16.
- Student number 2 uses 5 chalk, so k = 11.
- Student number 0 uses 5 chalk, so k = 6.
- Student number 1 uses 1 chalk, so k = 5.
- Student number 2 uses 5 chalk, so k = 0.
Student number 0 does not have enough chalk, so they will have to replace it.
Example 2:

Input: chalk = [3,4,1,2], k = 25
Output: 1
Explanation: The students go in turns as follows:
- Student number 0 uses 3 chalk so k = 22.
- Student number 1 uses 4 chalk so k = 18.
- Student number 2 uses 1 chalk so k = 17.
- Student number 3 uses 2 chalk so k = 15.
- Student number 0 uses 3 chalk so k = 12.
- Student number 1 uses 4 chalk so k = 8.
- Student number 2 uses 1 chalk so k = 7.
- Student number 3 uses 2 chalk so k = 5.
- Student number 0 uses 3 chalk so k = 2.
Student number 1 does not have enough chalk, so they will have to replace it.
 

Constraints:

chalk.length == n
1 <= n <= 105
1 <= chalk[i] <= 105
1 <= k <= 109
*/

/*
**Problem Statement:**
- You are given an array `chalk` where `chalk[i]` represents the amount of chalk the `i-th` student uses.
- There is a certain number of total chalk `k`. After distributing chalk among students, you need to determine the index of the student who will run out of chalk first after `k` units of chalk have been distributed.

**Approach:**
1. **Sum Calculation:**
   - First, calculate the total sum of the chalk required by all students.
   - If the total sum is less than or equal to `k`, then `k` is reduced by the total sum modulo. This accounts for the complete cycles of chalk distribution.

2. **Find the Student:**
   - Iterate through the `chalk` array and distribute chalk to each student.
   - If at any point `k` becomes less than the chalk required by the current student, that student is the one who will run out of chalk first.
   - Return the index of that student.

**Time Complexity:**
- The time complexity is `O(n)`, where `n` is the number of students, since we need to iterate through the `chalk` array twice: once for summing and once for finding the student.

**Space Complexity:**
- The space complexity is `O(1)`, as we are only using a few extra variables regardless of the input size.

**Example Usage:**
- Given `chalk = {5, 1, 5}` and `k = 22`, the function will return `0`, as the first student will run out of chalk first when `k = 22`.

*/

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Calculate the total amount of chalk required for one full round
        long long int sum = accumulate(chalk.begin(), chalk.end(), 0LL);

        // If k is larger than the total chalk sum, reduce k using modulo
        if(sum <= k) k = k % sum;

        int n = chalk.size();

        // Distribute chalk to students and find the student who will run out of chalk first
        for(int i = 0; i < n; i++){
            if(k < chalk[i]) return i;  // Return the index of the student who runs out of chalk
            k -= chalk[i];  // Subtract the used chalk from k
        }

        return -1;  // This line should never be reached
    }
};

// Example usage:
int main() {
    vector<int> chalk = {5, 1, 5};
    int k = 22;
    Solution sol;
    int result = sol.chalkReplacer(chalk, k);
    cout << "The student who will run out of chalk first is at index: " << result << endl;
    return 0;
}
