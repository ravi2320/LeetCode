/*
3014. Minimum Number of Pushes to Type Word I
Solved
Easy
Topics
Companies
Hint
You are given a string word containing distinct lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.

An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.


 

Example 1:


Input: word = "abcde"
Output: 5
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
Total cost is 1 + 1 + 1 + 1 + 1 = 5.
It can be shown that no other mapping can provide a lower cost.
Example 2:


Input: word = "xycdefghij"
Output: 12
Explanation: The remapped keypad given in the image provides the minimum cost.
"x" -> one push on key 2
"y" -> two pushes on key 2
"c" -> one push on key 3
"d" -> two pushes on key 3
"e" -> one push on key 4
"f" -> one push on key 5
"g" -> one push on key 6
"h" -> one push on key 7
"i" -> one push on key 8
"j" -> one push on key 9
Total cost is 1 + 2 + 1 + 2 + 1 + 1 + 1 + 1 + 1 + 1 = 12.
It can be shown that no other mapping can provide a lower cost.
 

Constraints:

1 <= word.length <= 26
word consists of lowercase English letters.
All letters in word are distinct.
*/

// Intuition: This approach attempts to distribute characters among the keys (2 to 9) in a round-robin fashion.
// It keeps track of how many times each key is pressed and adds the count to the total presses.

// Time Complexity: O(n), where n is the length of the word.
// Space Complexity: O(1), as we are using a fixed-size unordered map to store the presses per key.

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, int> mp; // To store the number of presses per key
        int ans = 0, mp_idx = 2; // Start from key 2

        // Iterate over each character in the word
        for(char ch : word){
            if(mp_idx > 9){
                mp_idx = 2; // Wrap around to key 2 after key 9
            }

            mp[mp_idx]++; // Increment the press count for the current key
            ans += mp[mp_idx]; // Add the press count to the total
            mp_idx++; // Move to the next key
        }

        return ans; // Return the total number of presses
    }
};


// Intuition: This approach calculates the number of key presses by considering the characters in groups of 8,
// which corresponds to the number of characters per key on an old phone. The total presses are calculated based on
// the number of complete groups and the remaining characters.

// Time Complexity: O(1), as the calculations involve basic arithmetic operations and do not depend on the size of the input.
// Space Complexity: O(1), as no additional data structures are used.

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        int rem = n % 8; // Remaining characters after grouping into sets of 8
        int div = n / 8; // Number of complete groups of 8

        ans = (div + 1) * rem; // Presses for the remaining characters in the last group
        while(div){
            ans += (8 * div); // Presses for each complete group of 8
            div--; // Move to the next group
        } 

        return ans; // Return the total number of presses
    }
};
