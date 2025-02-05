/*
1790. Check if One String Swap Can Make Strings Equal
Solved
Easy
Topics
Companies
Hint
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

 

Example 1:

Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".
Example 2:

Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.
Example 3:

Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.
 

Constraints:

1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 and s2 consist of only lowercase English letters.
*/

//Brute force
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2){
            return true;
        }

        string s1_swap = s1, s2_swap = s2;
        int n = s1.length();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(s1_swap[i], s1_swap[j]);
                if(s1_swap == s2){
                    return true;
                }
                else{
                   swap(s1_swap[i], s1_swap[j]); 
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(s2_swap[i], s2_swap[j]);
                if(s2_swap == s1){
                    return true;
                }
                else{
                   swap(s2_swap[i], s2_swap[j]); 
                }
            }
        }

        return false;
    }
};


//Better
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2){
            return true;
        }

        int n = s1.length();
        char ch1, ch2;
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                if(cnt == 0){
                    ch1 = s1[i];
                    ch2 = s2[i];
                }
                else if(cnt == 1){
                    if(s2[i] != ch1 || s1[i] != ch2){
                        return false;
                    }
                }
                else{
                    return false;
                }
                cnt++;
            }
        }

        return cnt == 2;
    }
};


//Optimized
/*
Approach:
1. Two strings `s1` and `s2` are considered almost equal if we can swap exactly one pair of characters in one of the strings to make them equal.
2. If the strings are already equal, we return `true` immediately.

Optimized Logic:
1. Instead of trying all possible swaps (which leads to O(N²) time complexity), we identify positions where the characters differ:
   - If there are more than 2 mismatches, it's impossible to make the strings equal with just one swap → return `false`.
   - If there are exactly 2 mismatched positions, check if swapping those characters in either string makes them equal.
   - If there are exactly 0 mismatches, the strings are already equal → return `true`.
   - If there is exactly 1 mismatch, we can't make them equal with just one swap → return `false`.

Time Complexity:
- **O(N)** where N is the length of the strings since we traverse the strings once.

Space Complexity:
- **O(1)** extra space (apart from storing mismatched indices).
*/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) {
            return true; // Already equal, no swap needed
        }

        vector<int> diffIndices;

        // Identify indices where characters differ
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diffIndices.push_back(i);
                // If more than 2 mismatches, swapping won't help
                if (diffIndices.size() > 2) {
                    return false;
                }
            }
        }

        // Check if swapping the mismatched characters makes the strings equal
        return diffIndices.size() == 2 &&
               s1[diffIndices[0]] == s2[diffIndices[1]] &&
               s1[diffIndices[1]] == s2[diffIndices[0]];
    }
};