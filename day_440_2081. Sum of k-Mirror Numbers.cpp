/*
2081. Sum of k-Mirror Numbers

avatar
Discuss Approach
arrow-up
Solved
Hard
Topics
premium lock icon
Companies
Hint
A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.

For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, which read the same both forward and backward.
On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the same both forward and backward.
Given the base k and the number n, return the sum of the n smallest k-mirror numbers.

 

Example 1:

Input: k = 2, n = 5
Output: 25
Explanation:
The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
  base-10    base-2
    1          1
    3          11
    5          101
    7          111
    9          1001
Their sum = 1 + 3 + 5 + 7 + 9 = 25. 
Example 2:

Input: k = 3, n = 7
Output: 499
Explanation:
The 7 smallest 3-mirror numbers are and their representations in base-3 are listed as follows:
  base-10    base-3
    1          1
    2          2
    4          11
    8          22
    121        11111
    151        12121
    212        21212
Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.
Example 3:

Input: k = 7, n = 17
Output: 20379000
Explanation: The 17 smallest 7-mirror numbers are:
1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596
 

Constraints:

2 <= k <= 9
1 <= n <= 30
*/

/*
Approach:
We need to find the sum of the first `n` natural numbers that are **palindromic in both base 10 and base `k`**.

Steps:
1. Start checking from number `1` upwards.
2. For each number `i`, check:
   - If it's a palindrome in base 10.
   - If it's a palindrome in base `k` (converted manually).
3. If both conditions hold, add `i` to the sum and increment count.
4. Repeat until we've found `n` such numbers.

Helper Functions:
- `toBaseK(int n, int k)`: Converts integer `n` to its base `k` string representation.
- `isPalindrome(string s)`: Checks if the given string is a palindrome.

Intuition:
Palindromes are symmetric. Checking them in two number systems ensures we only accept those that are "mirror" in both.

Time Complexity: O(m × log m)  
- Where `m` is the number of integers we check until we get `n` valid k-mirror numbers.
- `log m` accounts for digit operations and base conversion.

Space Complexity: O(log m)
- For base-k conversion string and checking palindromes.
*/

class Solution {
public:
    // Convert number to base-k string representation
    string toBaseK(int n, int k) {
        string res;
        while (n > 0) {
            res += (n % k) + '0';  // Append least significant digit
            n /= k;
        }
        reverse(res.begin(), res.end());  // Reverse to get correct order
        return res;
    }

    // Check if a string is a palindrome
    bool isPalindrome(const string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    // Main function to find the sum of first n k-mirror numbers
    long long kMirror(int k, int n) {
        int count = 0;      // Count of valid k-mirror numbers found
        long long sum = 0;  // Sum of valid numbers
        int i = 1;          // Start checking from 1

        while (count < n) {
            string base10 = to_string(i);        // Convert to base 10 string
            string baseK = toBaseK(i, k);        // Convert to base k string

            // Check if both are palindromes
            if (isPalindrome(base10) && isPalindrome(baseK)) {
                sum += i;
                count++;
            }
            i++;
        }

        return sum;
    }
};


/*
Approach:
This solution improves upon the brute-force method by **generating base-10 palindromic numbers directly**,
which significantly reduces the search space. Instead of checking every number one by one,
we only generate palindromes of increasing length, check if their base-k representations are palindromes too,
and count the first `n` such numbers.

Steps:
1. Start from palindrome length `L = 1` and increment as needed.
2. Generate palindromic numbers of length `L` by building them from their first half.
3. Convert each base-10 palindrome to base-k using `toBaseK()`.
4. If the base-k representation is also a palindrome, count it and add it to the sum.
5. Stop once `n` such k-mirror numbers are found.

Helper Functions:
- `toBaseK(n, k)`: Converts a number `n` to its base `k` representation string.
- `isPalindrome(s)`: Checks whether a string is a palindrome.

Time Complexity: ~O(n × log m)
- Each palindrome of length `L` is generated and converted to base `k`, where `m` is the max base-k mirror number found.
- Much better than checking every number blindly.

Space Complexity: O(log m)
- For storing base-k conversion strings and temporary palindrome strings.
*/

class Solution {
public:
    // Convert number to base-k string representation
    string toBaseK(long long n, int k) {
        if (n == 0) return "0";

        string res = "";
        while (n > 0) {
            res += to_string(n % k);  // Append base-k digit
            n /= k;
        }

        // No need to reverse here; base-k palindrome check doesn't require order
        return res;
    }

    // Check if a string is a palindrome
    bool isPalindrome(const string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    // Main function to find the sum of first n k-mirror numbers
    long long kMirror(int k, int n) {
        long long sum = 0;
        int L = 1;  // Length of palindrome

        while (n > 0) {
            int half_length = (L + 1) / 2;  // Half length used to build the palindrome

            long long min_num = pow(10, half_length - 1);  // Starting point for half
            long long max_num = pow(10, half_length) - 1;  // Ending point for half

            // Generate all half-length numbers and form palindromes
            for (long long num = min_num; num <= max_num; num++) {
                string first_half = to_string(num);
                string second_half = first_half;
                reverse(second_half.begin(), second_half.end());

                // Build full palindrome of length L
                string pal = (L % 2 == 0) ? (first_half + second_half)
                                          : (first
