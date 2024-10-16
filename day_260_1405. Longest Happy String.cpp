/*
1405. Longest Happy String
Solved
Medium
Topics
Companies
Hint
A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.
 

Constraints:

0 <= a, b, c <= 100
a + b + c > 0
*/

/*
Approach:
- This problem is solved using a greedy approach with a max-heap (priority queue).
- The idea is to always try to add the character with the highest remaining frequency to the result string, but avoid adding the same character more than twice consecutively.
- The characters with their counts are pushed into a max-heap. At each step, we try to add the most frequent character to the string.
- If the most frequent character has been added twice consecutively, we pick the next most frequent character (if available) and decrement its count.
- The process continues until no more valid characters can be added to the result string.

Time Complexity:
- O(n log 3) where `n` is the total number of characters to be added to the result string (`a + b + c`), and `log 3` comes from the priority queue which contains at most 3 elements (since there are only 3 different characters).
- In total, the complexity is effectively O(n).

Space Complexity:
- O(1) additional space besides the input since the priority queue holds at most 3 elements.

*/

class Solution {
    typedef pair<int, char> P; // Defining a pair to store character count and the character itself
public:
    // Main function to generate the longest diverse string
    string longestDiverseString(int a, int b, int c) {
        // Max-heap to store character counts and characters
        priority_queue<P, vector<P>> pq;

        // Push initial counts of characters into the priority queue if they are greater than 0
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string res = ""; // Resultant diverse string

        // While there are characters left in the priority queue
        while (!pq.empty()) {
            // Pop the most frequent character
            int currCnt = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();

            int n = res.length();
            // Check if the last two characters are the same as the current character
            if (n >= 2 && res[n-1] == currChar && res[n-2] == currChar) {
                // If the priority queue is empty, break since no valid character can be used
                if (pq.empty()) break;

                // Use the second most frequent character if available
                int nextCnt = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();

                // Add the next character to the result and decrease its count
                nextCnt--;
                res.push_back(nextChar);

                // If the count is still positive, push it back into the priority queue
                if (nextCnt > 0) pq.push({nextCnt, nextChar});
            } else {
                // Otherwise, add the current character to the result and decrease its count
                currCnt--;
                res.push_back(currChar);
            }

            // If the count of the current character is still positive, push it back into the priority queue
            if (currCnt > 0) pq.push({currCnt, currChar});
        }

        // Return the generated string
        return res;
    }
};
