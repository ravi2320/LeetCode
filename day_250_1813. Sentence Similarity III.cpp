/*
1813. Sentence Similarity III
Solved
Medium
Topics
Companies
Hint
You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.

Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.

For example,

s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.
Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.

 

Example 1:

Input: sentence1 = "My name is Haley", sentence2 = "My Haley"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".

Example 2:

Input: sentence1 = "of", sentence2 = "A lot of words"

Output: false

Explanation:

No single sentence can be inserted inside one of the sentences to make it equal to the other.

Example 3:

Input: sentence1 = "Eating right now", sentence2 = "Eating"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.

 

Constraints:

1 <= sentence1.length, sentence2.length <= 100
sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
The words in sentence1 and sentence2 are separated by a single space.
*/

/*
Approach:
1. The problem checks whether two sentences, `s1` and `s2`, are similar by either being identical or one being a subsequence of the other from both the start and end, with extra words in the middle of the longer sentence.
2. The approach first ensures that `s1` is always the longer or equal-length sentence by swapping if necessary.
3. Both sentences are split into words and stored in vectors.
4. Two pointers, one starting from the beginning and one from the end, compare words between `s1` and `s2`. The comparison continues as long as the words are identical from either the start or end.
5. The sentences are similar if all words of `s2` can be matched within `s1` either from the start or end.

Time Complexity:
- **O(n + m)**, where `n` is the number of words in `s1` and `m` is the number of words in `s2`. The time is mainly spent splitting the sentences and comparing words.

Space Complexity:
- **O(n + m)**, where `n` and `m` are the number of words in `s1` and `s2`, respectively. This space is used for storing the words in vectors.

*/

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        // Ensure s1 is the longer sentence
        if(s1.length() < s2.length()){
            return areSentencesSimilar(s2, s1); // Swap for consistency
        }

        // Split s1 and s2 into words
        vector<string> vec1, vec2;
        stringstream ss1(s1);
        string token;

        // Split s1 into words
        while(ss1 >> token){
            vec1.push_back(token);
        }

        // Split s2 into words
        stringstream ss2(s2);
        while(ss2 >> token){
            vec2.push_back(token);
        }

        // Two pointers to compare from the start and end
        int i = 0, j = vec1.size() - 1;
        int k = 0, l = vec2.size() - 1;

        // Compare from the start
        while(k <= l && vec1[i] == vec2[k]){
            i++, k++;
        }

        // Compare from the end
        while(k <= l && vec1[j] == vec2[l]){
            j--, l--;
        }

        // If all words in s2 are matched, return true
        return l < k;
    }
};


/*
Approach:
1. The task is to check whether two sentences, `s1` and `s2`, are similar. One is considered a subsequence of the other if all the words of the shorter sentence can be matched from either the start or the end of the longer sentence.
2. If `s1` is shorter than `s2`, swap them to ensure that the first string is always the longer one for consistent comparison.
3. The sentences are split into words and stored in deques, which allow efficient removal of elements from both ends.
4. A two-step process is used:
   - First, compare words from the front and remove matching words from both deques.
   - Then, compare words from the back and remove matching words.
5. If all words in the shorter sentence (`deq2`) are matched and deque becomes empty, the sentences are considered similar.

Time Complexity:
- **O(n + m)**, where `n` is the number of words in `s1` and `m` is the number of words in `s2`. The time is primarily spent splitting the sentences into words and comparing them.

Space Complexity:
- **O(n + m)**, where `n` and `m` are the number of words in `s1` and `s2`, respectively. This space is used for storing the words in the deques.

*/

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        // Ensure s1 is the longer sentence
        if(s1.length() < s2.length()){
            return areSentencesSimilar(s2, s1);  // Swap for consistency
        }

        // Split s1 and s2 into words and store them in deques
        deque<string> deq1, deq2;
        stringstream ss1(s1);
        string token;

        // Split s1 into words and add to deque1
        while(ss1 >> token){
            deq1.push_back(token);
        }

        // Split s2 into words and add to deque2
        stringstream ss2(s2);
        while(ss2 >> token){
            deq2.push_back(token);
        }

        // Compare from the front
        while(!deq2.empty() && deq1.front() == deq2.front()){
            deq1.pop_front();
            deq2.pop_front();
        }

        // Compare from the back
        while(!deq2.empty() && deq1.back() == deq2.back()){
            deq1.pop_back();
            deq2.pop_back();
        }

        // If all words in deq2 are matched, it becomes empty
        return deq2.empty();
    }
};
