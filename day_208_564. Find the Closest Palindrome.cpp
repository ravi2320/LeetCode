/*
564. Find the Closest Palindrome
Solved
Hard
Topics
Companies
Hint
Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.

The closest is defined as the absolute difference minimized between two integers.

 

Example 1:

Input: n = "123"
Output: "121"
Example 2:

Input: n = "1"
Output: "0"
Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
 

Constraints:

1 <= n.length <= 18
n consists of only digits.
n does not have leading zeros.
n is representing an integer in the range [1, 1018 - 1].
*/

/*
Intuition:
------------
A palindrome reads the same forwards and backwards. The nearest palindrome to a number can often be found by modifying its first half and mirroring it. However, edge cases occur when the number is close to powers of 10, like 100 or 999, where simpler patterns emerge.

Approach:
------------
1. Extract the first half of the number, then create palindromic candidates by mirroring it.
2. Adjust the first half by +1 and -1, then mirror these adjustments to create additional candidates.
3. Consider special cases: the smallest and largest palindromic numbers with one less and one more digit, respectively.
4. Compare all candidate palindromes to find the one closest to the original number. If there are ties, the smaller number is preferred.

Time Complexity:
-----------------
- Constructing each palindrome takes O(L), where L is the length of the number.
- We generate 5 potential palindromes, so the overall time complexity is O(L).

Space Complexity:
------------------
- We use a vector to store 5 potential results and a few extra variables, resulting in O(1) additional space beyond the input size.
*/

class Solution {
public:
    // Function to create a palindrome by mirroring the first half of the number
    long funcFirstHalf(long firstHalf, bool isEven) {
        long result = firstHalf;

        // If the length is odd, ignore the middle digit while mirroring
        if (!isEven) {
            firstHalf /= 10;
        }

        // Mirror the first half to create the palindrome
        while (firstHalf > 0) {
            int digit = firstHalf % 10;
            result = (result * 10) + digit;
            firstHalf /= 10;
        }

        return result;
    }

    string nearestPalindromic(string n) {
        int L = n.length();  // Length of the input number

        int firstHalfLength = (L + 1) / 2;  // Length of the first half

        // Convert the first half of the number to an integer
        long firstHalf = stol(n.substr(0, firstHalfLength));

        // Vector to store potential palindrome candidates
        vector<long> possibleResults;

        // Generate the palindrome candidates
        possibleResults.push_back(funcFirstHalf(firstHalf, L % 2 == 0));  // Mirror of the first half
        possibleResults.push_back(funcFirstHalf(firstHalf + 1, L % 2 == 0));  // Mirror of firstHalf + 1
        possibleResults.push_back(funcFirstHalf(firstHalf - 1, L % 2 == 0));  // Mirror of firstHalf - 1
        possibleResults.push_back((long)pow(10, L - 1) - 1);  // Largest palindrome with one digit less
        possibleResults.push_back((long)pow(10, L) + 1);  // Smallest palindrome with one digit more

        long diff = LONG_MAX;  // Initialize the smallest difference
        long result = INT_MAX;  // Initialize the closest palindrome
        long originalNum = stol(n);  // Convert input string to a long integer

        // Compare each candidate to find the closest palindrome
        for (long &num : possibleResults) {
            if (num == originalNum) continue;  // Skip the original number

            long currentDiff = abs(originalNum - num);
            if (currentDiff < diff) {
                diff = currentDiff;
                result = num;
            } else if (currentDiff == diff) {
                result = min(result, num);  // If tie, choose the smaller number
            }
        }

        return to_string(result);  // Convert the closest palindrome back to string
    }
};
