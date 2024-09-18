/*
179. Largest Number
Solved
Medium
Topics
Companies
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109
*/

/*
Approach:
1. We are tasked with arranging a list of non-negative integers such that they form the largest possible number.
2. We convert each number to a string for easier comparison of concatenated values.
3. The key to the problem is custom sorting based on string comparison:
   - For two strings `s1` and `s2`, we compare `s1+s2` and `s2+s1`. 
   - If `s1+s2 > s2+s1`, then `s1` should come before `s2` in the final result.
4. After sorting, we concatenate the strings to form the largest number.
5. We handle the edge case where the result might be "0" (all numbers are zero).

Time Complexity:
- O(n log n): The time complexity is dominated by the sorting step, where `n` is the size of the input array. 
  Sorting each string comparison involves concatenating two strings, which is O(1) on average due to fixed-length numbers.

Space Complexity:
- O(n): Space is used for storing the string representations of the numbers and the final result.

*/

class Solution {
public:
    // Function to return the largest number that can be formed by the array
    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        // Convert all integers to strings and store them in a vector
        for(auto &x : nums) {
            arr.push_back(to_string(x));
        }

        // Custom sort the strings based on which concatenation gives a larger value
        sort(arr.begin(), arr.end(), [](string &s1, string &s2) {
            return s1 + s2 > s2 + s1;  // Compare concatenated results
        });

        // Concatenate all sorted strings to form the largest number
        string ans = "";
        for(string &str : arr) {
            ans += str;
        }

        // If the largest number starts with '0', return "0" (all elements are zeros)
        return ans[0] == '0' ? "0" : ans;
    }
};
