/*
2094. Finding 3-Digit Even Numbers
Solved
Easy
Topics
Companies
Hint
You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.
The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.

 

Example 1:

Input: digits = [2,1,3,0]
Output: [102,120,130,132,210,230,302,310,312,320]
Explanation: All the possible integers that follow the requirements are in the output array. 
Notice that there are no odd integers or integers with leading zeros.
Example 2:

Input: digits = [2,2,8,8,2]
Output: [222,228,282,288,822,828,882]
Explanation: The same digit can be used as many times as it appears in digits. 
In this example, the digit 8 is used twice each time in 288, 828, and 882. 
Example 3:

Input: digits = [3,7,5]
Output: []
Explanation: No even integers can be formed using the given digits.
 

Constraints:

3 <= digits.length <= 100
0 <= digits[i] <= 9
*/

/*
Approach:
- We are given a list of digits and asked to form all 3-digit **even** numbers using **distinct indices**.
- The number must be:
  1. A valid 3-digit number (i.e., cannot start with 0).
  2. Even (i.e., last digit must be even).
- We use 3 nested loops to try all permutations of 3 digits with different indices.
- If a combination is valid (leading digit not zero and last digit even), we store it in a set to avoid duplicates.
- Finally, we convert the set to a vector and return it sorted.

Intuition:
- Use brute-force by checking all combinations of 3 different digits.
- Use a `set` to automatically avoid duplicates and maintain sorted order.

Time Complexity: O(n^3)
- We check all combinations of i, j, k (with i ≠ j ≠ k) → O(n^3)

Space Complexity: O(1)
- Fixed number of 3-digit even numbers possible: max 900 (from 100 to 998), so space is constant.

*/

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> st;

        // Try all 3-digit combinations with different indices
        for(int i = 0; i < n; i++) {
            if(digits[i] == 0) continue; // Leading digit can't be 0

            for(int j = 0; j < n; j++) {
                if(i == j) continue; // Indices must be different

                for(int k = 0; k < n; k++) {
                    // All indices must be distinct and last digit must be even
                    if(i == k || j == k || digits[k] % 2 != 0) continue;

                    // Form the number and insert into set
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    st.insert(num);
                }
            }
        }

        // Convert set to vector
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};

/*
Approach:
- We want to find all 3-digit even numbers using digits from the input list, without reusing a digit more than its frequency.
- Instead of generating all permutations, we iterate through all possible 3-digit even numbers (100 to 998 with step of 2).
- For each number, we check if we have enough digits available to form it by checking against the frequency count.
- If yes, we add it to the result.

Intuition:
- Reduce unnecessary computations by only checking 3-digit even numbers directly.
- This is faster and cleaner than checking all 3-permutations of digits manually.

Time Complexity: O(450)
- We check at most 450 3-digit even numbers (from 100 to 998 in steps of 2).
- For each number, operations are constant time.

Space Complexity: O(1)
- Frequency array and result vector store a constant number of entries (max 450 results).

*/

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        // Frequency count of digits
        vector<int> freq(10, 0);
        for(int &x : digits){
            freq[x]++;
        }

        vector<int> res;
        // Check every 3-digit even number
        for(int num = 100; num < 1000; num += 2){
            int hundred = num / 100;
            int ten = (num / 10) % 10;
            int one = num % 10;

            // Decrease frequency to simulate usage
            freq[hundred]--;
            freq[ten]--;
            freq[one]--;

            // If all digits are still >= 0, we can form the number
            if(freq[hundred] >= 0 && freq[ten] >= 0 && freq[one] >= 0){
                res.push_back(num);
            }

            // Restore frequencies
            freq[hundred]++;
            freq[ten]++;
            freq[one]++;
        }

        return res;
    }
};