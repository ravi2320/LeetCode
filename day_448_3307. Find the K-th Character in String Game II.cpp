/*
3307. Find the K-th Character in String Game II
Solved

avatar
Discuss Approach
arrow-up
Hard
Topics
premium lock icon
Companies
Hint
Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k. You are also given an integer array operations, where operations[i] represents the type of the ith operation.

Now Bob will ask Alice to perform all operations in sequence:

If operations[i] == 0, append a copy of word to itself.
If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
Return the value of the kth character in word after performing all the operations.

Note that the character 'z' can be changed to 'a' in the second type of operation.

 

Example 1:

Input: k = 5, operations = [0,0,0]

Output: "a"

Explanation:

Initially, word == "a". Alice performs the three operations as follows:

Appends "a" to "a", word becomes "aa".
Appends "aa" to "aa", word becomes "aaaa".
Appends "aaaa" to "aaaa", word becomes "aaaaaaaa".
Example 2:

Input: k = 10, operations = [0,1,0,1]

Output: "b"

Explanation:

Initially, word == "a". Alice performs the four operations as follows:

Appends "a" to "a", word becomes "aa".
Appends "bb" to "aa", word becomes "aabb".
Appends "aabb" to "aabb", word becomes "aabbaabb".
Appends "bbccbbcc" to "aabbaabb", word becomes "aabbaabbbbccbbcc".
 

Constraints:

1 <= k <= 1014
1 <= operations.length <= 100
operations[i] is either 0 or 1.
The input is generated such that word has at least k characters after all operations.
*/

/*
Approach:
The problem involves recursively tracking how a string evolves through a sequence of operations. 
At each operation:
- If `operations[i] == 0`: the string doubles without change.
- If `operations[i] == 1`: the string doubles, but the second half increments each character by 1.

We simulate only up to the point where the length of the resulting string becomes ≥ `k`. 
Then we recursively trace which half the kth character lies in and reverse the effect accordingly.

Intuition:
Each operation doubles the length. The kth character lies in the second half of some operation, 
so we reduce the problem to finding the character in the corresponding position of the first half 
(recursively), and then apply the effect of the operation (i.e., increment if required).

Time Complexity: O(log k) — Each recursive call reduces the problem by half.
Space Complexity: O(log k) — Due to recursion stack.
*/

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // Base case: first character is always 'a'
        if(k == 1) 
            return 'a';

        int n = operations.size();
        long long len = 1;
        int opType;
        long long newK;

        // Find the first operation where length becomes ≥ k
        for(int i = 0; i < n; i++) {
            len *= 2;

            // Found the operation where kth character lies in second half
            if(len >= k) {
                newK = k - len / 2;  // Mirror into the first half
                opType = operations[i];
                break;
            }
        }

        // Recursive call for mirrored position
        char res = kthCharacter(newK, operations);

        // Apply the operation effect
        if(opType == 0)
            return res;

        return res == 'z' ? 'a' : res + 1;
    }
};
