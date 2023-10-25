/*

7. Reverse Integer
Solved
Medium
Topics
Companies
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1

*/

/*
class Solution {
public:
    int reverse(int x) {
        int rem = 0, cnt = 0; 
        long long ans = 0;

        if(x < 0)
        {
            x = abs(x);
            cnt = 1;
        }
        while(x > 0)
        {
            rem = x % 10;
            ans = ans * 10 + rem;
            x /= 10;
        }
        if(ans > 2147483647 || ans < -2147483647)
            return 0;
        return (int)(cnt == 1 ? -ans:ans);
    }
};
*/
class Solution {
public:
    int reverse(int x) {
        long ans = 0;

        while(x)
        {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        if(ans > INT_MAX || ans < INT_MIN)
            return 0;
        return ans;
    }
};