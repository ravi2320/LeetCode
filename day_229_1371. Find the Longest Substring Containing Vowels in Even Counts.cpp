/*
1371. Find the Longest Substring Containing Vowels in Even Counts
Solved
Medium
Topics
Companies
Hint
Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

 

Example 1:

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
Example 2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
Example 3:

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
 

Constraints:

1 <= s.length <= 5 x 10^5
s contains only lowercase English letters.
*/

/*
Approach:
1. We need to find the longest substring that contains all vowels ('a', 'e', 'i', 'o', 'u') in even counts.
2. Use a state-tracking mechanism to track whether each vowel occurs an odd or even number of times.
   - We maintain a 5-bit string (`currState`), where each bit represents whether a vowel's count is odd (1) or even (0).
3. If the current state has been seen before, then the substring from the first occurrence of that state to the current index is valid.
   - We use a hash map (`mp`) to store the first occurrence of each state.
4. At each step, check if the current state has appeared before. If yes, update the result.
5. Return the maximum length of the valid substring.

Time Complexity:
- O(n): We iterate through the string once, and each operation (updating state and checking the map) takes constant time.

Space Complexity:
- O(n): We store the states in a hash map, which could have up to `n` unique entries in the worst case.

*/

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        
        // Map to store the first occurrence of each state (vowel parity pattern)
        unordered_map<string, int> mp;
        
        // Initial state: all vowels are even, represented as "00000"
        string currState = "00000";
        mp[currState] = -1;  // Initial condition, -1 to handle case when the substring starts from index 0

        vector<int> state(5, 0);  // Track the parity of each vowel ('a', 'e', 'i', 'o', 'u')

        int res = 0;  // Variable to store the longest valid substring length

        // Traverse the string and update the state
        for(int i = 0; i < n; i++) {
            // Update state based on the current character
            if (s[i] == 'a') state[0] ^= 1; 
            else if (s[i] == 'e') state[1] ^= 1;
            else if (s[i] == 'i') state[2] ^= 1;
            else if (s[i] == 'o') state[3] ^= 1;
            else if (s[i] == 'u') state[4] ^= 1;

            // Convert the state vector to a string
            currState = "";
            for (int j = 0; j < 5; j++) {
                currState += to_string(state[j]);
            }

            // Check if this state has been encountered before
            if (mp.find(currState) != mp.end()) {
                // Update result with the longest valid substring
                res = max(res, i - mp[currState]);
            } else {
                // Store the first occurrence of this state
                mp[currState] = i;
            }
        }

        return res;  // Return the longest valid substring length
    }
};


/*
Approach:
1. The task is to find the longest substring in which all vowels ('a', 'e', 'i', 'o', 'u') appear an even number of times.
2. We can use a bitmask to track the parity (even or odd occurrence) of each vowel:
   - A 5-bit integer `mask` is used, where each bit represents whether a vowel's count is odd (1) or even (0).
3. As we iterate through the string:
   - We toggle the corresponding bit in `mask` when we encounter a vowel.
   - If the same mask appears again, it means that the vowels between these two positions have even counts.
   - We use a hash map (`mp`) to store the first occurrence of each mask.
4. For every vowel parity state, we calculate the possible longest valid substring and update the result.

Time Complexity:
- O(n): We traverse the string once, and each operation (toggling bits, hash map operations) takes constant time.

Space Complexity:
- O(n): We use a hash map to store the mask values, which can have up to `n` entries in the worst case.

*/

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        unordered_map<int, int> mp; // Map to store the first occurrence of each mask (bit pattern of vowel parities)

        int mask = 0; // Bitmask to track the parity of vowels
        mp[mask] = -1; // Initialize with mask 0 at index -1 to handle cases starting from the beginning

        int res = 0; // Variable to store the length of the longest valid substring

        // Traverse the string
        for(int i = 0; i < n; i++) {
            // Update the mask based on the current character
            if(s[i] == 'a') {
                mask ^= (1 << 0);  // Toggle the bit corresponding to 'a'
            } else if(s[i] == 'e') {
                mask ^= (1 << 1);  // Toggle the bit corresponding to 'e'
            } else if(s[i] == 'i') {
                mask ^= (1 << 2);  // Toggle the bit corresponding to 'i'
            } else if(s[i] == 'o') {
                mask ^= (1 << 3);  // Toggle the bit corresponding to 'o'
            } else if(s[i] == 'u') {
                mask ^= (1 << 4);  // Toggle the bit corresponding to 'u'
            }

            // Check if this mask has been seen before
            if(mp.find(mask) != mp.end()) {
                // If the mask is already present, calculate the length of the substring
                res = max(res, i - mp[mask]);
            } else {
                // Otherwise, store the first occurrence of this mask
                mp[mask] = i;
            }
        }

        return res; // Return the length of the longest valid substring
    }
};
