/*
3043. Find the Length of the Longest Common Prefix
Solved
Medium
Topics
Companies
Hint
You are given two arrays with positive integers arr1 and arr2.

A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.

A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have a common prefix 565 while 1223 and 43456 do not have a common prefix.

You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.

Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.

 

Example 1:

Input: arr1 = [1,10,100], arr2 = [1000]
Output: 3
Explanation: There are 3 pairs (arr1[i], arr2[j]):
- The longest common prefix of (1, 1000) is 1.
- The longest common prefix of (10, 1000) is 10.
- The longest common prefix of (100, 1000) is 100.
The longest common prefix is 100 with a length of 3.
Example 2:

Input: arr1 = [1,2,3], arr2 = [4,4,4]
Output: 0
Explanation: There exists no common prefix for any pair (arr1[i], arr2[j]), hence we return 0.
Note that common prefixes between elements of the same array do not count.
 

Constraints:

1 <= arr1.length, arr2.length <= 5 * 104
1 <= arr1[i], arr2[i] <= 108
*/

/*
 * Approach:
 * 1. This function calculates the longest common prefix between two arrays of integers by examining the prefixes formed by progressively dividing each number by 10.
 * 2. For each number in `arr1`, it stores all possible prefixes in a set.
 * 3. For each number in `arr2`, it checks if any of its prefixes exist in the set from step 2.
 * 4. The result is the maximum length of a matching prefix found between the two arrays.
 * 
 * Time Complexity: O(m * log(M) + n * log(M)), where `m` and `n` are the sizes of `arr1` and `arr2` respectively, 
 * and `M` is the maximum value in the arrays. For each number, we may divide it by 10 repeatedly, 
 * which takes approximately O(log(M)) steps.
 * 
 * Space Complexity: O(m * log(M)), where `m` is the size of `arr1` and `log(M)` is the number of prefixes stored for each element in `arr1`.
 */

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;  // Set to store prefixes of numbers from arr1

        // Store all prefixes of each number in arr1
        for(int val : arr1) {
            while(!st.count(val) && val > 0) {  // While val not in set and still positive
                st.insert(val);  // Insert current prefix into set
                val /= 10;  // Reduce val by dividing by 10
            }
        }

        int res = 0;  // Variable to store the maximum prefix length
        // Check for common prefixes with numbers in arr2
        for(int num : arr2) {
            while(!st.count(num) && num > 0) {  // Reduce num to its prefixes
                num /= 10;
            }

            if(num > 0) {
                // Calculate the length of the prefix and update the result
                res = max(res, (int)log10(num) + 1);  // log10(num) gives the number of digits - 1
            }
        }

        return res;  // Return the length of the longest common prefix
    }
};


/*
 * Approach:
 * 1. This solution uses a Trie (prefix tree) to find the longest common prefix between two arrays of integers.
 * 2. We first insert all numbers from `arr1` into the Trie, storing each digit as a child node.
 * 3. Then, for each number in `arr2`, we search the Trie to find the length of the longest common prefix by traversing the Trie digit by digit.
 * 4. The result is the maximum length of a matching prefix found between the two arrays.
 * 
 * Time Complexity: O(m * log(M) + n * log(M)), where `m` and `n` are the sizes of `arr1` and `arr2`, 
 * and `M` is the maximum value in the arrays. Each number has at most O(log(M)) digits.
 * 
 * Space Complexity: O(m * log(M)), where `m` is the size of `arr1` and `log(M)` is the number of digits in the maximum value.
 * The space is used to store the Trie nodes for all the digits in `arr1`.
 */

struct Trie {
    Trie* children[10];  // Array to store pointers to child nodes (digits 0-9)
};

class Solution {
public:
    // Function to create and initialize a new Trie node
    Trie* getTrieNode() {
        Trie* node = new Trie();
        // Initialize all child pointers to NULL
        for(int i = 0; i < 10; i++) {
            node->children[i] = NULL;
        }
        return node;
    }

    // Function to insert a number into the Trie
    void insert(int num, Trie* root) {
        string strNum = to_string(num);  // Convert number to string to process digit by digit
        Trie* crawl = root;  // Start from the root of the Trie

        // Traverse the Trie, inserting digits of the number
        for(char &ch : strNum) {
            int idx = ch - '0';  // Get the digit

            // If the child for this digit doesn't exist, create a new Trie node
            if(!crawl->children[idx]) {
                crawl->children[idx] = getTrieNode();
            }

            // Move to the child node
            crawl = crawl->children[idx];
        }
    }

    // Function to search the longest common prefix for a number in the Trie
    int search(int num, Trie* root) {
        string strNum = to_string(num);  // Convert number to string to process digit by digit
        Trie* crawl = root;  // Start from the root of the Trie

        int len = 0;  // Variable to store the length of the common prefix

        // Traverse the Trie while the digits match
        for(char &ch : strNum) {
            int idx = ch - '0';  // Get the digit

            // If there is no child for this digit, stop the search
            if(!crawl->children[idx]) break;

            len++;  // Increment the prefix length
            crawl = crawl->children[idx];  // Move to the child node
        } 

        return len;  // Return the length of the common prefix
    }

    // Function to find the longest common prefix between two arrays
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* root = getTrieNode();  // Create the root of the Trie

        // Insert all numbers from arr1 into the Trie
        for(int &num : arr1) {
            insert(num, root);
        }

        int res = 0;  // Variable to store the maximum common prefix length

        // Search for the longest common prefix for each number in arr2
        for(int &num : arr2) {
            res = max(res, search(num, root));
        }

        return res;  // Return the length of the longest common prefix
    }
};
