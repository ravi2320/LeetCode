/*
Sum of Two No-Zero Integers

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

Given an integer n, return a list of two integers [a, b] where:

a and b are No-Zero integers.
a + b = n
The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

 

Example 1:

Input: n = 2
Output: [1,1]
Explanation: Let a = 1 and b = 1.
Both a and b are no-zero integers, and a + b = 2 = n.
Example 2:

Input: n = 11
Output: [2,9]
Explanation: Let a = 2 and b = 9.
Both a and b are no-zero integers, and a + b = 11 = n.
Note that there are other valid answers as [8, 3] that can be accepted.
 

Constraints:

2 <= n <= 104
*/

/*
Approach:
1. Iterate over possible splits of `n` into two numbers `i` and `n-i`.
2. For each candidate pair, check if both numbers do not contain the digit '0'.
3. As soon as a valid pair is found, return it.

Intuition:
The task is to decompose `n` into two numbers such that neither contains zero.
Since `n` is relatively small (constraint allows brute force), 
we can check all possible splits up to n/2, ensuring one valid answer exists.

Time Complexity: O(n * log n)  
- We check up to n/2 pairs.
- Each check scans digits of numbers → O(log n) per check.

Space Complexity: O(1)  
- Only constant extra variables used.
*/

class Solution {
public:
    // Helper function to check if number contains digit '0'
    bool check(int n){
        while(n){
            if(n % 10 == 0){   // if digit is zero
                return false;
            }
            n /= 10;
        }
        return true;
    }

    // Main function to return pair of no-zero integers
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i <= n/2; i++){
            // Check if both parts have no zeros
            if(check(i) && check(n - i)){
                return {i, n - i};
            }
        }
        return {}; // should not reach here as solution always exists
    }
};

/*
Approach:
1. We greedily construct two numbers `a` and `b` such that:
   - Their sum equals `n`.
   - Neither contains the digit '0'.
2. Start with `a = n` and `b = 0`.
3. For each digit (from least significant to most significant):
   - If current digit of `n` is `1`, we assign `2` to `b` at this place value 
     (and reduce from `a`) to avoid creating a '0' in `a`.
   - Otherwise, we assign `1` to `b` at this place value.
4. Continue until `n` is reduced to `1` or less.
5. Return `{a, b}`.

Intuition:
Instead of brute forcing all possible splits, 
we ensure digit-by-digit that no number has a '0'.
By "borrowing" from `a` and giving to `b`, 
we guarantee both remain valid no-zero integers.

Time Complexity: O(log n)  
- We process each digit of `n` once.

Space Complexity: O(1)  
- Only a few integer variables are used.
*/

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = n;          // initially a = n
        int b = 0;          // b will be constructed
        int placeValue = 1; // track current digit's place value (1, 10, 100...)

        // process digit by digit
        while(n > 1){
            int take = 1;   // default contribution to b at this place

            if(n % 10 == 1){ // if digit is 1, using 1 would make a digit 0 in 'a'
                take = 2;   // so use 2 instead to avoid zero
            }

            // adjust a and b accordingly
            a = a - take * placeValue;
            b = b + take * placeValue;

            // move to next digit
            n = (n - take) / 10;
            placeValue *= 10;
        }

        return {a, b};
    }
};
