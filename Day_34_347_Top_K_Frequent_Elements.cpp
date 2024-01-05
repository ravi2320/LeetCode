/*
347. Top K Frequent Elements
Solved
Medium
Topics
Companies
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        map<int, vector<int>, greater<int>> sortedMap; // Use greater<int> to sort in descending order

        // Count the frequency of each element
        for (int num : nums)
            frequencyMap[num]++;

        // Populate the sortedMap with frequencies as keys and corresponding elements as values
        for (auto& entry : frequencyMap)
            sortedMap[entry.second].push_back(entry.first);

        vector<int> result;
        for (auto& entry : sortedMap) {
            for (int num : entry.second) {
                result.push_back(num);
                if (result.size() == k)
                    return result;
            }
        }

        return result;
    }
};
