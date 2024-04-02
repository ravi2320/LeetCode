/*
205. Isomorphic Strings
Solved
Easy
Topics
Companies
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

// Intuition:
// We use two unordered maps to keep track of the mapping from characters in string s to characters in string t, and vice versa.
// We iterate through both strings simultaneously and check if the mapping is consistent.
// If any inconsistency is found, we return false.
// Otherwise, we return true.

// Time complexity: O(n), where n is the length of the input strings s and t.
// Space complexity: O(n) since we use two unordered maps to store the mappings, each of which can store up to n unique characters.
class Solution {
public:
    // Function to check if two strings are isomorphic
    bool isIsomorphic(string s, string t) {
        
        // Maps to store the mapping from characters in s to characters in t, and vice versa
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        // Length of the input strings
        int n = s.length();

        // Iterate through both strings simultaneously
        for(int i = 0; i < n; i++){

            // Current characters in both strings
            char ch1 = s[i];
            char ch2 = t[i];

            // Check if the mapping is consistent
            if((mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2) ||
                (mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1)
            )
                return false;
            
            // Update the mappings
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        } 

        // If no inconsistency is found, return true
        return true;
    }
};


// Intuition:
// We use two vectors to store the mapping from characters in string s to characters in string t, and vice versa.
// We initialize both vectors with -1 as a marker for characters that haven't been mapped yet.
// We iterate through both strings simultaneously and check if the mapping is consistent.
// If any inconsistency is found, we return false.
// Otherwise, we return true.

// Time complexity: O(n), where n is the length of the input strings s and t.
// Space complexity: O(1) since the space used by the vectors is constant, independent of the input size.
class Solution {
public:
    // Function to check if two strings are isomorphic
    bool isIsomorphic(string s, string t) {
        // Vectors to store the mapping from characters in s to characters in t, and vice versa
        vector<int> mp1(256, -1);
        vector<int> mp2(256, -1);

        // Length of the input strings
        int n = s.length();

        // Iterate through both strings simultaneously
        for(int i = 0; i < n; i++){

            // Current characters in both strings
            char ch1 = s[i];
            char ch2 = t[i];

            // Check if the mapping is consistent
            if((mp1[ch1] != -1 && mp1[ch1] != ch2) ||
                (mp2[ch2] != -1 && mp2[ch2] != ch1)
            )
                return false;
        
            // Update the mappings
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        // If no inconsistency is found, return true
        return true;
    }
};
