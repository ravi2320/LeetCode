/*
166. Fraction to Recurring Decimal

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 4, denominator = 333
Output: "0.(012)"
 

Constraints:

-231 <= numerator, denominator <= 231 - 1
denominator != 0
*/

/*
Approach:
1. Handle sign:
   - If numerator * denominator < 0, prepend "-" to the result.
   - Work with absolute values to simplify division and remainder handling.

2. Integer division:
   - Compute abs(numerator) / abs(denominator) → integer part of the fraction.
   - Append to result string.

3. Handle remainder:
   - If remainder == 0 → no fractional part, just return result.

4. Fractional part:
   - Append "." to result.
   - Use long division:
     - Multiply remainder by 10.
     - Extract digit = remainder / denominator.
     - Append digit to result.
     - Update remainder = remainder % denominator.
   - If a remainder repeats → cycle detected, insert "(" at first occurrence and append ")" at the end.

5. Use a hashmap:
   - Maps remainder → index in result string where that remainder first appeared.
   - This helps detect repeating decimals.

Intuition:
- Decimal expansion repeats if the remainder repeats.
- Hashmap ensures we can track when a cycle begins.

Time Complexity:
- O(n) where n is the length of repeating cycle (at most denominator different remainders).
- Each step processes one digit of the fractional part.

Space Complexity:
- O(n) for hashmap storing remainders.
- O(1) extra for variables.

*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        // Case: numerator is 0 → answer is "0"
        if(numerator == 0){
            return "0";
        }

        string res;

        // If fraction is negative
        if((long long)numerator * (long long)denominator < 0){
            res = "-";
        }

        // Work with absolute values (avoid overflow with long long)
        long long absNumerator = llabs((long long)numerator);
        long long absDenominator = llabs((long long)denominator);
        
        // Integer division part
        long long intDiv = absNumerator / absDenominator;
        res += to_string(intDiv);

        // Initial remainder
        long long remainder = absNumerator % absDenominator; 

        // If perfectly divisible → return result
        if(remainder == 0){
            return res;
        }

        // Otherwise, handle fractional part
        res += ".";

        // Map to store remainder → index in result string
        unordered_map<long long, int> mp;

        while(remainder != 0){
            // If we have seen this remainder before, cycle detected
            if(mp.count(remainder)){
                res.insert(mp[remainder], "("); // insert "(" at the index where cycle started
                res += ")";                     // append ")"
                break;
            }

            // Store remainder's index in result string
            mp[remainder] = res.length();

            // Long division step
            remainder *= 10;
            int digit = remainder / absDenominator;
            res += to_string(digit);

            remainder = remainder % absDenominator;
        }

        return res;
    }
};
