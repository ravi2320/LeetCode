/*
2145. Count the Hidden Sequences
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed array of n integers differences, which describes the differences between each pair of consecutive integers of a hidden sequence of length (n + 1). More formally, call the hidden sequence hidden, then we have that differences[i] = hidden[i + 1] - hidden[i].

You are further given two integers lower and upper that describe the inclusive range of values [lower, upper] that the hidden sequence can contain.

For example, given differences = [1, -3, 4], lower = 1, upper = 6, the hidden sequence is a sequence of length 4 whose elements are in between 1 and 6 (inclusive).
[3, 4, 1, 5] and [4, 5, 2, 6] are possible hidden sequences.
[5, 6, 3, 7] is not possible since it contains an element greater than 6.
[1, 2, 3, 4] is not possible since the differences are not correct.
Return the number of possible hidden sequences there are. If there are no possible sequences, return 0.

 

Example 1:

Input: differences = [1,-3,4], lower = 1, upper = 6
Output: 2
Explanation: The possible hidden sequences are:
- [3, 4, 1, 5]
- [4, 5, 2, 6]
Thus, we return 2.
Example 2:

Input: differences = [3,-4,5,1,-2], lower = -4, upper = 5
Output: 4
Explanation: The possible hidden sequences are:
- [-3, 0, -4, 1, 2, 0]
- [-2, 1, -3, 2, 3, 1]
- [-1, 2, -2, 3, 4, 2]
- [0, 3, -1, 4, 5, 3]
Thus, we return 4.
Example 3:

Input: differences = [4,-7,2], lower = 3, upper = 6
Output: 0
Explanation: There are no possible hidden sequences. Thus, we return 0.
 

Constraints:

n == differences.length
1 <= n <= 105
-105 <= differences[i] <= 105
-105 <= lower <= upper <= 105
*/

/*
Intuition:
We are given the *differences* between consecutive elements of a hidden array.
Our task is to determine how many such arrays exist such that each element is within [lower, upper].

The core idea is:
- Start from an arbitrary value `x` (we'll determine the range of valid `x`).
- Apply each difference to form the array: x, x + diff1, x + diff1 + diff2, ...
- Track the minimum and maximum values that this cumulative sum can reach.
- Ensure that the entire resulting array stays within the range [lower, upper].

Let:
- `minVal` be the lowest cumulative value reached,
- `maxVal` be the highest cumulative value reached,
Then valid starting `x` must satisfy:
  lower ≤ x + minVal ≤ x + maxVal ≤ upper

Which leads to the final formula:
  total valid x = (upper - maxVal) - (lower - minVal) + 1

If this range is invalid (i.e., ≤ 0), return 0.

Approach:
1. Initialize a cumulative sum starting from 0.
2. Track minimum and maximum cumulative values as we apply differences.
3. Apply the formula to compute valid starting values.

Time Complexity: O(N)
- One pass through the `differences` array.

Space Complexity: O(1)
- Constant extra space.
*/

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr = 0;       // current cumulative sum
        int minVal = 0;     // minimum cumulative sum seen
        int maxVal = 0;     // maximum cumulative sum seen

        for(int &diff : differences){
            curr += diff;                      // build cumulative sum
            minVal = min(minVal, curr);        // track minimum
            maxVal = max(maxVal, curr);        // track maximum
        }

        // Calculate number of valid starting values
        int totalValid = (upper - maxVal) - (lower - minVal) + 1;

        return totalValid <= 0 ? 0 : totalValid;
    }
};
