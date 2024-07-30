/*
1653. Minimum Deletions to Make String Balanced
Solved
Medium
Topics
Companies
Hint
You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.

 

Example 1:

Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
Example 2:

Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.
 

Constraints:

1 <= s.length <= 105
s[i] is 'a' or 'b'​​.
*/

/*
Intuition:
The problem is to determine the minimum number of deletions required to make the string `s` valid such that all 'b's appear before all 'a's. To achieve this, we can use a stack to track the characters as we iterate through the string. We only need to remove an 'a' if it is preceded by a 'b', as this situation violates the desired order. By counting the number of such invalid 'ba' pairs, we can determine the minimum number of deletions required.

Time Complexity:
The time complexity of this solution is O(N), where N is the length of the string `s`. This is because we iterate through the string once, pushing and popping elements from the stack.

Space Complexity:
The space complexity is O(N) in the worst case, where N is the length of the string, due to the space required by the stack. However, in practical cases, the stack will contain fewer elements since we pop elements when encountering invalid pairs.
*/

class Solution {
public:
    // Function to find the minimum number of deletions to make the string valid
    int minimumDeletions(string s) {
        stack<char> st; // Stack to track the characters
        int cnt = 0;    // Counter for the number of deletions

        // Iterate through each character in the string
        for(char x : s){
            // Check for an invalid 'ba' pair and handle it
            if(!st.empty() && x == 'a' && st.top() == 'b'){
                st.pop(); // Remove the 'b' from the stack
                cnt++;    // Increment the deletion counter
            }
            else{
                st.push(x); // Push the current character onto the stack
            }
        }

        return cnt; // Return the total number of deletions
    }
};


/*
Intuition:
The problem requires finding the minimum number of deletions to make a string `s` valid such that all 'b's come before all 'a's. A more efficient approach can be achieved using two arrays:
1. `left_B[i]`: This array counts the number of 'b's to the left of index `i`.
2. `right_A[i]`: This array counts the number of 'a's to the right of index `i`.

The goal is to minimize the sum of the two counts at each index, representing the total deletions needed if we "cut" the string at that index to separate all 'b's to the left from all 'a's to the right.

Time Complexity:
The time complexity is O(N), where N is the length of the string `s`, since we traverse the string multiple times to fill the `left_B` and `right_A` arrays and to find the minimum deletions.

Space Complexity:
The space complexity is O(N) due to the two auxiliary arrays `left_B` and `right_A` used to store the counts.

*/

class Solution {
public:
    // Function to find the minimum number of deletions to make the string valid
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> left_B(n, 0);  // Counts of 'b's to the left of each index
        vector<int> right_A(n, 0); // Counts of 'a's to the right of each index

        // Calculate the counts of 'b's to the left of each index
        for (int i = 1; i < n; i++) {
            left_B[i] = left_B[i - 1] + (s[i - 1] == 'b' ? 1 : 0);
        }

        // Calculate the counts of 'a's to the right of each index
        for (int i = n - 2; i >= 0; i--) {
            right_A[i] = right_A[i + 1] + (s[i + 1] == 'a' ? 1 : 0);
        }

        int mini = INT_MAX;

        // Find the minimum number of deletions required
        for (int i = 0; i < n; i++) {
            mini = min(mini, left_B[i] + right_A[i]);
        }

        return mini;
    }
};


/*
Intuition:
The problem requires finding the minimum number of deletions to make a string `s` valid such that all 'b's come before all 'a's. We can achieve this by using a single array `right_A` to count the number of 'a's to the right of each index. Additionally, we maintain a counter `cnt_b` for the number of 'b's encountered so far from the start.

The idea is to consider the string up to each index `i` and compute the deletions needed:
- `right_A[i]` gives the number of 'a's to the right of `i`, which should be deleted if they appear before any 'b's.
- `cnt_b` keeps track of the number of 'b's encountered so far, which should be deleted if they appear after any 'a's.

By iterating through the string and updating these values, we can find the minimum number of deletions needed.

Time Complexity:
The time complexity is O(N), where N is the length of the string `s`, as we traverse the string twice: once to populate `right_A` and once to compute the minimum deletions.

Space Complexity:
The space complexity is O(N) due to the `right_A` array used to store the counts.

*/

class Solution {
public:
    // Function to find the minimum number of deletions to make the string valid
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> right_A(n, 0); // Counts of 'a's to the right of each index

        int cnt_a = 0; // Counter for 'a's encountered
        // Populate the right_A array with the number of 'a's to the right of each index
        for (int i = n - 1; i >= 0; i--) {
            right_A[i] = cnt_a;
            if (s[i] == 'a') cnt_a++;
        }

        int cnt_b = 0;  // Counter for 'b's encountered
        int mini = INT_MAX;  // Variable to store the minimum deletions required

        // Iterate through the string to calculate the minimum deletions
        for (int i = 0; i < n; i++) {
            mini = min(mini, right_A[i] + cnt_b); // Calculate minimum deletions at index i
            if (s[i] == 'b') cnt_b++;  // Increment the count of 'b's if encountered
        }

        return mini; // Return the minimum deletions required
    }
};


/*
Intuition:
To make the string valid where all 'b's appear before all 'a's, we need to determine the minimum deletions required. This can be achieved by iterating through the string and counting the number of 'a's and 'b's that need to be removed to meet the condition.

1. **Initial Count of 'a's**: Count all the 'a's in the string, as they represent potential deletions if found after 'b's in the final valid string.
2. **Track Deletions**: As we iterate through the string, we update the count of 'a's (`cnt_a`) and 'b's (`cnt_b`). For every 'a' encountered, decrement the `cnt_a` as it would now be to the left of the current position. For every 'b' encountered, increment the `cnt_b` as they represent 'b's that have to be before 'a's to the right.
3. **Calculate Minimum Deletions**: The deletions required at each position are the sum of remaining 'a's to be moved to the right and the number of 'b's to be moved to the left.

Time Complexity:
The time complexity is O(N), where N is the length of the string `s`, as we iterate through the string twice: once for counting 'a's and once for computing the minimum deletions.

Space Complexity:
The space complexity is O(1) for auxiliary space, as we only use a few integer variables and do not use any additional data structures proportional to the input size.

*/

class Solution {
public:
    // Function to find the minimum number of deletions to make the string valid
    int minimumDeletions(string s) {
        int n = s.length();
        int cnt_a = 0; // Count of 'a's in the entire string

        // Count the total number of 'a's in the string
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') cnt_a++;
        }

        int cnt_b = 0; // Counter for 'b's encountered
        int mini = INT_MAX; // Variable to store the minimum deletions required

        // Iterate through the string to calculate the minimum deletions
        for (int i = 0; i < n; i++) {
            // Decrement the count of 'a's when encountered
            if (s[i] == 'a') cnt_a--;

            // Calculate minimum deletions at index i
            mini = min(mini, cnt_a + cnt_b);

            // Increment the count of 'b's when encountered
            if (s[i] == 'b') cnt_b++;
        }

        return mini; // Return the minimum deletions required
    }
};
