/*
592. Fraction Addition and Subtraction
Solved
Medium
Topics
Companies
Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

 

Example 1:

Input: expression = "-1/2+1/2"
Output: "0/1"
Example 2:

Input: expression = "-1/2+1/2+1/3"
Output: "1/3"
Example 3:

Input: expression = "1/3-1/2"
Output: "-1/6"
 

Constraints:

The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1, 10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
*/

/*
Intuition:
- To add fractions, we need to find a common denominator. For each fraction in the string, compute the result by multiplying the current numerator with the existing denominator and the existing numerator with the current denominator.
- Simplify the resulting fraction by dividing both the numerator and denominator by their Greatest Common Divisor (GCD).

Time Complexity:
- The time complexity is O(n), where n is the length of the input string `expr`. This is because each character is processed once.
- Computing the GCD takes O(log(min(a, b))), which is very efficient.

Space Complexity:
- The space complexity is O(1), as we only use a few extra variables for computation, and no additional space is required that scales with the input size.
*/

class Solution {
public:
    string fractionAddition(string expr) {
        int numo = 0; // Numerator of the resultant fraction
        int deno = 1; // Denominator of the resultant fraction
        int n = expr.size(); // Size of the input string
        int i = 0; // Index to traverse the string

        // Traverse the input string to process each fraction
        while(i < n) {
            int currNumo = 0; // Current fraction's numerator
            int currDeno = 0; // Current fraction's denominator
            bool isNeg = (expr[i] == '-'); // Check if the current fraction is negative

            // Skip the sign if present
            if(expr[i] == '+' || expr[i] == '-') {
                i++;
            }

            // Build the current numerator
            while(i < n && isdigit(expr[i])) {
                currNumo = (currNumo * 10) + expr[i] - '0';
                i++;
            }

            i++; // Skipping the '/' character

            if(isNeg) {
                currNumo *= -1; // Apply the negative sign if needed
            }

            // Build the current denominator
            while(i < n && isdigit(expr[i])) {
                currDeno = (currDeno * 10) + expr[i] - '0';
                i++;
            }

            // Update the resultant numerator and denominator
            numo = (numo * currDeno) + (deno * currNumo);
            deno = deno * currDeno;
        }

        // Simplify the resultant fraction using GCD
        int GCD = abs(__gcd(numo, deno));
        numo /= GCD;
        deno /= GCD;

        // Return the simplified fraction as a string
        return to_string(numo) + "/" + to_string(deno);
    }
};
