/*
1865. Finding Pairs With a Certain Sum

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

Add a positive integer to an element of a given index in the array nums2.
Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
Implement the FindSumPairs class:

FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.
 

Example 1:

Input
["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"]
[[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4], [0, 1], [1, 1], [7]]
Output
[null, 8, null, 2, 1, null, null, 11]

Explanation
FindSumPairs findSumPairs = new FindSumPairs([1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]);
findSumPairs.count(7);  // return 8; pairs (2,2), (3,2), (4,2), (2,4), (3,4), (4,4) make 2 + 5 and pairs (5,1), (5,5) make 3 + 4
findSumPairs.add(3, 2); // now nums2 = [1,4,5,4,5,4]
findSumPairs.count(8);  // return 2; pairs (5,2), (5,4) make 3 + 5
findSumPairs.count(4);  // return 1; pair (5,0) makes 3 + 1
findSumPairs.add(0, 1); // now nums2 = [2,4,5,4,5,4]
findSumPairs.add(1, 1); // now nums2 = [2,5,5,4,5,4]
findSumPairs.count(7);  // return 11; pairs (2,1), (2,2), (2,4), (3,1), (3,2), (3,4), (4,1), (4,2), (4,4) make 2 + 5 and pairs (5,3), (5,5) make 3 + 4
 

Constraints:

1 <= nums1.length <= 1000
1 <= nums2.length <= 105
1 <= nums1[i] <= 109
1 <= nums2[i] <= 105
0 <= index < nums2.length
1 <= val <= 105
1 <= tot <= 109
At most 1000 calls are made to add and count each.
*/

/*
Approach:
- We store two arrays `arr1` and `arr2` from the constructor.
- Maintain a frequency map `mp` of values in `arr2` to quickly count how many times a complement (tot - arr1[i]) exists.
- When `add(index, val)` is called:
    - We update the frequency of the old value and insert the new one after adding `val`.
- When `count(tot)` is called:
    - For each element in `arr1`, we check how many times `tot - arr1[i]` appears in `arr2` using the map.

Intuition:
- Since `arr1` is fixed and `arr2` can be updated, we precompute the frequency map of `arr2` to make the `count` operation fast.
- This avoids repeated traversal of `arr2` for each count call.

Time Complexity:
- Constructor: O(n) for building the map where n = size of nums2
- add(): O(1) since we only update two entries in the map
- count(): O(m), where m = size of nums1

Space Complexity: O(n), for the frequency map of nums2
*/

class FindSumPairs {
    vector<int> arr1, arr2;
    unordered_map<int, int> mp;  // Frequency map of arr2 values

public:
    // Constructor: store arrays and build frequency map for arr2
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for (int &x : nums2) {
            mp[x]++;
        }
    }
    
    // Add value to arr2[index] and update frequency map
    void add(int index, int val) {
        mp[arr2[index]]--;           // Decrease count of current value
        arr2[index] += val;          // Update the value
        mp[arr2[index]]++;           // Increase count of new value
    }
    
    // Count number of (i, j) such that arr1[i] + arr2[j] == tot
    int count(int tot) {
        int cnt = 0;
        for (int j = 0; j < arr1.size(); j++) {
            int complement = tot - arr1[j];
            if (mp.count(complement)) {
                cnt += mp[complement];
            }
        }
        return cnt;
    }
};

/**
 * Example usage:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int result = obj->count(tot);
 */