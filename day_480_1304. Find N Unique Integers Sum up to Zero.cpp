/*
1304. Find N Unique Integers Sum up to Zero

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given an integer n, return any array containing n unique integers such that they add up to 0.

 

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]
 

Constraints:

1 <= n <= 1000
*/

/*
Approach:
1. For a given number `n`, we want to generate `n` distinct integers whose sum is zero.
2. We can take pairs of positive and negative integers: (1, -1), (2, -2), ..., (n/2, -(n/2)).
   - These pairs cancel each other out, contributing a sum of 0.
3. If `n` is odd, we also add `0` to make the total count equal to `n`.

Intuition:
The problem requires constructing a sequence that sums to zero.  
By adding symmetric pairs of positive and negative integers, we guarantee balance.  
For odd `n`, adding `0` ensures both the count and the sum conditions are satisfied.

Time Complexity: O(n) → We iterate up to `n/2` and insert elements.  
Space Complexity: O(n) → The result vector stores `n` elements.
*/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;

        // Add pairs (i, -i) which cancel each other out
        for(int i = 1; i <= n/2; ++i) {
            ans.push_back(i);
            ans.push_back(-i);
        }

        // If n is odd, include 0
        if(n % 2 != 0) 
            ans.push_back(0);

        return ans;
    }
};
