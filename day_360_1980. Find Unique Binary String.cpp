/*
1980. Find Unique Binary String
Solved
Medium
Topics
Companies
Hint
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.
Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 

Constraints:

n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.
*/

/**
 * Approach:
 * - We use **backtracking** to generate binary strings of length `n`.
 * - We store all given binary strings in an **unordered_set** for O(1) lookup.
 * - We **generate** binary strings recursively and stop at the first missing one.
 *
 * Intuition:
 * - A binary string of length `n` has **2^n** possible values.
 * - Given `n` strings, there **must** be at least one missing.
 * - **Backtracking** efficiently finds a missing string.
 *
 * Time Complexity:
 * - **O(2^N)** in the worst case (generating all possible strings).
 * - But we stop early once we find a valid string, making it **efficient**.
 *
 * Space Complexity:
 * - **O(N)** for storing the current string in recursion.
 * - **O(N)** for storing the given set.
 */

class Solution {
public:
    void solve(string &num, int &n, unordered_set<string> &st, string &res){
        // Base case: If num reaches length n
        if(num.size() == n){
            if(!st.count(num)){ // If num is not in the given set, we found our answer
                res = num;
            }
            return;
        }

        // Try both '0' and '1' at the current position
        for(int i = 0; i <= 1; i++){
            num.push_back(i + '0'); // Convert int to char and append

            solve(num, n, st, res);
            
            if(!res.empty()) return; // Stop once we find the result

            num.pop_back(); // Backtrack
        }
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st(nums.begin(), nums.end()); // Store given binary strings in a set
        int n = nums.size();

        string num = "", res = "";

        solve(num, n, st, res); // Start backtracking to find missing binary string

        return res;
    }
};

/**
 * Approach:
 * - Convert given binary strings to **decimal values** and store them in an unordered_set.
 * - Iterate from **0 to N**, checking for a missing number.
 * - Convert the first missing number back to a binary string.
 *
 * Intuition:
 * - A binary string of length `n` represents values **0 to 2^n - 1**.
 * - We can store existing numbers and find the **smallest missing one** in O(N).
 * - Using **bitset** helps efficiently convert decimal back to binary.
 *
 * Time Complexity:
 * - **O(N)** to store numbers in a set.
 * - **O(N)** to find the missing number.
 * - Overall: **O(N)**
 *
 * Space Complexity:
 * - **O(N)** for the unordered set.
 * - **O(1)** for string storage.
 */

class Solution {
public:
    // Converts a binary string to decimal integer
    int binaryToDecimal(string &str, int n) {
        int num = 0, base = 1;

        for(int i = n - 1; i >= 0; i--) {
            if(str[i] == '1') {
                num += base;
            }
            base *= 2;
        }
        return num;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        // Store all binary numbers in the set (converted to decimal)
        for(int i = 0; i < n; i++) {
            st.insert(binaryToDecimal(nums[i], n));
        } 

        // Find the first missing number
        for(int i = 0; i <= n; i++) {
            if(!st.count(i)) {
                // Convert missing number to binary and return the last n bits
                return bitset<16>(i).to_string().substr(16 - n, n);
            }
        } 

        return "";
    }
};

/**
 * Approach:
 * - Construct a **new binary string** using the **diagonal elements** of the input.
 * - If `nums[i][i] == '1'`, append `'0'`, otherwise append `'1'`.
 * - This guarantees the new string **differs from all given strings** at index `i`.
 *
 * Intuition:
 * - We leverage the **Cantor's diagonalization** technique.
 * - Since each string is unique in the input, **flipping the diagonal bit** ensures our result is different.
 * - No extra space is needed beyond the result string.
 *
 * Time Complexity:
 * - **O(N)** (Iterates once through `nums`).
 *
 * Space Complexity:
 * - **O(1)** (Only uses a string of size `N`).
 */

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res = "";

        // Flipping the diagonal elements
        for (int i = 0; i < n; i++) {
            res.push_back(nums[i][i] == '1' ? '0' : '1');
        }

        return res;
    }
};