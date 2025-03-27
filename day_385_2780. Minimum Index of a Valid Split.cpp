/*
2780. Minimum Index of a Valid Split
Solved
Medium
Topics
Companies
Hint
An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.

You are given a 0-indexed integer array nums of length n with one dominant element.

You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

0 <= i < n - 1
nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

Return the minimum index of a valid split. If no valid split exists, return -1.

 

Example 1:

Input: nums = [1,2,2,2]
Output: 2
Explanation: We can split the array at index 2 to obtain arrays [1,2,2] and [2]. 
In array [1,2,2], element 2 is dominant since it occurs twice in the array and 2 * 2 > 3. 
In array [2], element 2 is dominant since it occurs once in the array and 1 * 2 > 1.
Both [1,2,2] and [2] have the same dominant element as nums, so this is a valid split. 
It can be shown that index 2 is the minimum index of a valid split. 
Example 2:

Input: nums = [2,1,3,1,1,1,7,1,2,1]
Output: 4
Explanation: We can split the array at index 4 to obtain arrays [2,1,3,1,1] and [1,7,1,2,1].
In array [2,1,3,1,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 > 5.
In array [1,7,1,2,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 > 5.
Both [2,1,3,1,1] and [1,7,1,2,1] have the same dominant element as nums, so this is a valid split.
It can be shown that index 4 is the minimum index of a valid split.
Example 3:

Input: nums = [3,3,3,3,7,2,2]
Output: -1
Explanation: It can be shown that there is no valid split.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
nums has exactly one dominant element.
*/

/*
    🔹 Approach:
    - Use two hash maps `mp1` and `mp2`. 
        - `mp1` will store the count of elements from the left part (up to index `i`).
        - `mp2` will store the count of elements from the right part (from index `i+1` onward).
    - For each element at index `i`, check if it appears more than half in both the left and right parts of the array.
        - Left part: `mp1[nums[i]] > n1 / 2`
        - Right part: `mp2[nums[i]] > n2 / 2`
    - If such an index is found, return the index `i`.

    🔹 Intuition:
    - The goal is to find an index where the element at that index is the majority in both the left and right parts of the array.
    - We adjust the count of elements in both parts as we move through the array.

    🔹 Time Complexity:
    - **O(N)**, where `N` is the size of the array. We are iterating over the array twice (one to populate `mp2` and once to check conditions).
    
    🔹 Space Complexity:
    - **O(N)** for storing the counts in hash maps.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp1, mp2;

        // Initialize mp2 with the frequency of each element in nums
        for(int &num : nums){
            mp2[num]++;
        }

        // Traverse through the array and update mp1 and mp2
        for(int i = 0; i < n; i++) {
            mp1[nums[i]]++;   // Increment count in left part (mp1)
            mp2[nums[i]]--;   // Decrement count in right part (mp2)

            int n1 = i + 1;  // Number of elements in the left part
            int n2 = n - i - 1;  // Number of elements in the right part

            // Check if current element is majority in both parts
            if(mp1[nums[i]] > n1 / 2 && mp2[nums[i]] > n2 / 2) {
                return i;  // Return the index where both parts have majority element
            }
        }

        return -1;  // No such index found
    }
};

// Driver Code
int main() {
    vector<int> nums = {1, 2, 3, 3, 3};
    Solution obj;
    cout << obj.minimumIndex(nums) << endl;  // Output: 2
    return 0;
}

/*
    🔹 Approach:
    - **Step 1: Find the Majority Element using the Boyer-Moore Voting Algorithm.**
      - The majority element is the element that appears more than `n/2` times.
    - **Step 2: Count the occurrences of the majority element.**
      - Count how many times `majEle` appears in `nums`.
    - **Step 3: Iterate through the array to check for the minimum index.**
      - Maintain `cnt` (count of `majEle` in the left part) and `remCnt` (remaining count in the right part).
      - Check if `majEle` is dominant in both the left and right partitions.

    🔹 Intuition:
    - The key observation is that if there exists an index `i` where the majority element remains dominant in both left and right partitions, that is our answer.
    - We leverage the **Boyer-Moore Majority Vote Algorithm** to efficiently find the majority element in O(N) time.

    🔹 Time Complexity:
    - **O(N)** since we traverse the array only a few times (finding majority element, counting, and checking dominance conditions).
    
    🔹 Space Complexity:
    - **O(1)** since we use only a few extra variables.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the majority element using Boyer-Moore Voting Algorithm
        int majEle = -1, cnt = 0;
        for (int &num : nums) {
            if (cnt == 0) {
                majEle = num;
                cnt = 1;
            } else if (majEle == num) {
                cnt++;
            } else {
                cnt--;
            }
        }

        // Step 2: Count total occurrences of the majority element
        int majCnt = 0;
        for (int &num : nums) {
            if (num == majEle) majCnt++;
        }

        // Step 3: Find the minimum index where majority conditions hold
        int remCnt = 0;
        cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == majEle) {
                cnt++;  // Count occurrences in the left partition
            }

            remCnt = majCnt - cnt;  // Remaining occurrences in the right partition
            int n1 = i + 1, n2 = n - i - 1;

            // Check if `majEle` is dominant in both left and right partitions
            if (cnt * 2 > n1 && remCnt * 2 > n2) {
                return i;
            }
        }

        return -1;  // No valid split found
    }
};

// Driver Code
int main() {
    vector<int> nums = {1, 2, 3, 3, 3};
    Solution obj;
    cout << obj.minimumIndex(nums) << endl;  // Output: 2
    return 0;
}