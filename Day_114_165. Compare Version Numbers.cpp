/*
165. Compare Version Numbers
Solved
Medium
Topics
Companies
Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
 

Example 1:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
Example 2:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: version1 does not specify revision 2, which means it is treated as "0".
Example 3:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0 < 1, so version1 < version2.
 

Constraints:

1 <= version1.length, version2.length <= 500
version1 and version2 only contain digits and '.'.
version1 and version2 are valid version numbers.
All the given revisions in version1 and version2 can be stored in a 32-bit integer.
*/

// Intuition:
// This class provides a method to compare two version numbers represented as strings.
// It first splits the input strings 'version1' and 'version2' into tokens using the '.' delimiter,
// then compares the corresponding tokens one by one.
// If the token is missing in one version, it's considered as 0.
// It iterates through the tokens of both versions and compares them numerically.
// If a token in 'version1' is less than the corresponding token in 'version2', it returns -1.
// If a token in 'version1' is greater than the corresponding token in 'version2', it returns 1.
// If both versions are equal up to a certain point, it continues comparing the remaining tokens.
// If all tokens are equal, it returns 0.

// Time Complexity: O(max(N, M))
// - N is the number of tokens in 'version1'.
// - M is the number of tokens in 'version2'.
// - The algorithm iterates through the tokens of both versions once.

// Space Complexity: O(N + M)
// - The space required to store the tokens of both versions.

#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    // Function to split the version string into tokens
    vector<string> getTokens(string version) {
        stringstream ss(version);
        string token = "";
        vector<string> tokens;
        while (getline(ss, token, '.')) {
            tokens.push_back(token);
        }
        return tokens;
    } 

    // Function to compare two version strings
    int compareVersion(string version1, string version2) {
        vector<string> v1 = getTokens(version1); // Split 'version1' into tokens
        vector<string> v2 = getTokens(version2); // Split 'version2' into tokens

        int n = v1.size(); // Number of tokens in 'version1'
        int m = v2.size(); // Number of tokens in 'version2'
        int i = 0; // Index for iterating through tokens

        // Compare tokens of both versions
        while (i < n || i < m) {
            // Convert tokens to integers (consider 0 if token is missing)
            int a = i < n ? stoi(v1[i]) : 0;
            int b = i < m ? stoi(v2[i]) : 0;

            // Compare tokens numerically
            if (a < b)
                return -1;
            else if (a > b)
                return 1;
            else
                i++; // Move to the next token if current tokens are equal
        }
        return 0; // Both versions are equal
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    string version1 = "1.2.3";
    string version2 = "1.2.3";
    int result = obj.compareVersion(version1, version2);
    cout << "Comparison Result: " << result << endl; // Output: Comparison Result: 0 (Equal)
    return 0;
}
