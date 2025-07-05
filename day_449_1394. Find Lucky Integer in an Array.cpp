/*
1394. Find Lucky Integer in an Array

avatar
Discuss Approach
arrow-up
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.

 

Example 1:

Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
Example 2:

Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
Example 3:

Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.
 

Constraints:

1 <= arr.length <= 500
1 <= arr[i] <= 500
*/

/*
Approach:
We iterate over each element in the array. For each unique value, we count how many times it appears in the array.
If the count equals the value itself, it's considered a "lucky" number. We track the maximum such number.
We skip repeating the same number again to avoid redundant counting.

Intuition:
A number is lucky if it appears in the array exactly as many times as its value.
This brute-force approach checks every number for this condition and updates the result.

Time Complexity: O(n^2) — Nested loop to count frequency for each element.
Space Complexity: O(1) — No extra space used (excluding input).
*/

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            // Skip if already considered or smaller than current answer
            if(arr[i] != ans && arr[i] > ans) {
                int cnt = 0;

                // Count frequency of arr[i]
                for(int j = 0; j < n; j++) {
                    if(arr[i] == arr[j])
                        cnt++;
                }

                // Update answer if it's a lucky number
                if(cnt == arr[i])
                    ans = arr[i];
            }
        }

        return ans;
    }
};


/*
Approach:
We use a hash map (unordered_map) to store the frequency of each number in the array.
Then, we iterate through the map to find numbers whose value is equal to their frequency.
Among all such numbers, we return the maximum one. If no such number exists, we return -1.

Intuition:
A "lucky" integer is defined as a number whose count in the array equals the number itself.
Using a frequency map allows quick lookup and comparison for this condition.

Time Complexity: O(n) — where n is the size of the input array.
Space Complexity: O(n) — for storing the frequency map.
*/

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;

        // Count frequency of each number
        for(int &num : arr){
            mp[num]++;
        }

        int ans = -1;

        // Check for "lucky" integers (number == frequency)
        for(auto &itr : mp){
            if(itr.first == itr.second){
                ans = max(ans, itr.first); // Update max lucky number
            }
        }

        return ans;
    }
};
