/*
791. Custom Sort String
Solved
Medium
Topics
Companies
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

 

Example 1:

Input:  order = "cba", s = "abcd" 

Output:  "cbad" 

Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".

Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:

Input:  order = "bcafg", s = "abcd" 

Output:  "bcad" 

Explanation: The characters "b", "c", and "a" from order dictate the order for the characters in s. The character "d" in s does not appear in order, so its position is flexible.

Following the order of appearance in order, "b", "c", and "a" from s should be arranged as "b", "c", "a". "d" can be placed at any position since it's not in order. The output "bcad" correctly follows this rule. Other arrangements like "bacd" or "bcda" would also be valid, as long as "b", "c", "a" maintain their order.

 

Constraints:

1 <= order.length <= 26
1 <= s.length <= 200
order and s consist of lowercase English letters.
All the characters of order are unique.
*/

class Solution {
public:
    string customSortString(string order, string s) {
        //order string contain only lowercase english letter hence to reduce space complexity we are using arr[26]
        int count[26];

        //calculating count of each char in s and store in count array 
        for(char x : s){
            count[x - 'a']++; //take index of array eg, x = b is 66 therefore 66 - 65('a') = 1 is the index of arr[26]
        }

        string ans = ""; //store the ans
        for(char x : order){ //iterate each cahr in order
            if(count[x - 'a']){ //if count of char in x > 0 means present in string s
                int i = count[x - 'a']; // taking count of char
                while(i--){
                    ans += x;  //putting char in answer based on no of occurences
                }
                count[x - 'a'] = 0; // make it zero to mark it done
            }
        }
        for(int i = 0; i < 26; i++){ // if any char in string s is remaining
            while(count[i]--){          // while(count of remaining char become zero)
                ans += (char) 'a' + i;
            }
        }
        return ans;
    }
};


//Approach 2

class Solution {
public:
    string customSortString(string order, string s) {
        // To store the sequence of char in order
        vector<int> index(26, -1); // Vector to store index of each character

        // Populate index vector with character indices from order
        for(int i = 0; i < order.size(); i++){
            char ch = order[i]; // Accessing char at ith position in order
            index[ch - 'a'] = i; // Assign index of char in order
        }

        // Comparator function based on the index vector
        auto myComparator = [&index](char &ch1, char &ch2){
            return index[ch1 - 'a'] < index[ch2 - 'a'];
        };

        // Sort string s based on order defined by index vector
        sort(s.begin(), s.end(), myComparator);

        return s; // Return sorted string
    }
};



