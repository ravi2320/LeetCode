/*
1925. Count Square Sum Triples

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.

Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

 

Example 1:

Input: n = 5
Output: 2
Explanation: The square triples are (3,4,5) and (4,3,5).
Example 2:

Input: n = 10
Output: 4
Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).
 

Constraints:

1 <= n <= 250
*/

/*
Approach:
---------
We need to count the number of Pythagorean triples (a, b, c) such that:
    a^2 + b^2 = c^2  
and all values are within 1 to n.

To avoid double-counting, we iterate:
    a from 1 to n
    b from a+1 to n  (ensures a < b)

For each pair (a, b):
    - Compute s = a^2 + b^2
    - Check if s is a perfect square
    - Let x = sqrt(s), if x*x == s and x ≤ n, we found a valid triple (a, b, x)

Why ans += 2?
-------------
The problem counts both (a, b, c) and (b, a, c) as separate valid triples,
even though mathematically they are the same.  
Since we enforce a < b to avoid duplicate computation, we add 2 for each match.

Intuition:
----------
We brute-force over all possible pairs of legs (a, b) of a right triangle,
verify whether the hypotenuse is a perfect square, and count valid solutions.
The limit n is small enough for an O(n²) solution.

Time Complexity:
----------------
O(n²)  
We iterate over all pairs (a, b) up to n.

Space Complexity:
-----------------
O(1)  
Only a few integer variables are used.

*/

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;

        // Loop for first leg 'a'
        for(int a = 1; a <= n; a++){
            // Loop for second leg 'b', starting from a+1 to avoid duplicate checks
            for(int b = a + 1; b <= n; b++){
                
                // Compute a^2 + b^2
                int s = a * a + b * b;

                // Check if s is a perfect square
                int x = sqrt(s);

                // If x*x == s → perfect square AND x ≤ n → valid hypotenuse
                if(x * x == s && x <= n)
                    ans += 2;   // Count both (a, b, x) and (b, a, x)
            }
        }

        return ans;
    }
};
