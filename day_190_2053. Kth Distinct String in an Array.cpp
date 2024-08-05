/*
2053. Kth Distinct String in an Array
Solved
Easy
Topics
Companies
Hint
A distinct string is a string that is present only once in an array.

Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".

Note that the strings are considered in the order in which they appear in the array.

 

Example 1:

Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"
Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned. 
Example 2:

Input: arr = ["aaa","aa","a"], k = 1
Output: "aaa"
Explanation:
All strings in arr are distinct, so the 1st string "aaa" is returned.
Example 3:

Input: arr = ["a","b","a"], k = 3
Output: ""
Explanation:
The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".
 

Constraints:

1 <= k <= arr.length <= 1000
1 <= arr[i].length <= 5
arr[i] consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

// Intuition: To find the k-th distinct string in an array, we first count the frequency of each string using an 
// unordered map. Then, we iterate through the array again to find the k-th string that has a frequency of 1 
// (i.e., is distinct).

// Time Complexity: O(n) where n is the number of strings in the array. We iterate over the array twice, once for 
// counting frequencies and once for finding the k-th distinct string.

// Space Complexity: O(n) for storing the frequency of each string in the unordered map.

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;

        // Count the frequency of each string in the array
        for(string &str : arr) {
            mp[str]++;
        }

        int cnt = 0;
        // Iterate through the array to find the k-th distinct string
        for(string &str : arr) {
            if(mp[str] == 1) {
                cnt++;
            }

            if(cnt == k) {
                return str;
            }
        }

        // If there are fewer than k distinct strings, return an empty string
        return "";
    }
};

int main() {
    Solution sol;
    vector<string> arr = {"a", "b", "a", "c", "b", "d", "e"};
    int k = 2;

    cout << sol.kthDistinct(arr, k) << endl; // Output: "c"

    return 0;
}
