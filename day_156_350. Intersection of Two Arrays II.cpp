/*
350. Intersection of Two Arrays II
Solved
Easy
Topics
Companies
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
 

Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

// Intuition:
// The goal is to find the intersection of two arrays, meaning the common elements between them. 
// To achieve this efficiently, we first sort both arrays. Then, we use a two-pointer technique to 
// traverse both arrays and find common elements. This approach ensures that we can find intersections 
// in linear time relative to the size of the arrays after sorting.

// Time Complexity: O(n log n + m log m), where n is the size of nums1 and m is the size of nums2. 
// The sorting step takes O(n log n) and O(m log m) respectively. The two-pointer traversal takes O(n + m).
// Space Complexity: O(1), ignoring the space used by the result vector. We only use a few extra variables.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Sort both arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        vector<int> res; // Result vector to store the intersection elements
        
        // Two-pointer technique to find intersections
        while(i < n && j < m) {
            if(nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return res;
    }
};


// Intuition:
// The problem is to find the intersection of two arrays, which means finding common elements between them. 
// We use hash maps to count the occurrences of each element in both arrays. Then, we iterate through one hash map 
// and check if the element exists in the other hash map. If it does, we add the minimum count of that element 
// from both maps to the result vector.

// Time Complexity: O(n + m), where n is the size of nums1 and m is the size of nums2. 
// We traverse both arrays once to fill the hash maps and then traverse one of the hash maps to build the result.
// Space Complexity: O(n + m), for storing the elements and their counts in two hash maps.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2; // Hash maps to store the counts of elements
        vector<int> res; // Result vector to store the intersection elements
        int n = nums1.size();
        int m = nums2.size();

        // Count the occurrences of each element in nums1
        for(int i = 0; i < n; i++) {
            mp1[nums1[i]]++;
        }

        // Count the occurrences of each element in nums2
        for(int j = 0; j < m; j++) {
            mp2[nums2[j]]++;
        }

        // Find the intersection elements
        for(auto itr : mp1) {
            if(mp2.find(itr.first) != mp2.end()) {
                int count = min(itr.second, mp2[itr.first]);
                while(count--) {
                    res.push_back(itr.first);
                }
            }
        }

        return res;
    }
};


// Intuition:
// The goal is to find the intersection of two arrays, meaning the common elements between them. 
// We use a hash map to count the occurrences of each element in the first array. Then, we iterate through 
// the second array, and for each element, if it exists in the hash map with a count greater than zero, 
// we add it to the result and decrease the count in the hash map.

// Time Complexity: O(n + m), where n is the size of nums1 and m is the size of nums2. 
// We traverse nums1 to fill the hash map and nums2 to find the intersection elements.
// Space Complexity: O(n), for storing the elements and their counts in the hash map.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1; // Hash map to store the counts of elements in nums1
        vector<int> res; // Result vector to store the intersection elements
        int n = nums1.size();
        int m = nums2.size();

        // Count the occurrences of each element in nums1
        for(int i = 0; i < n; i++) {
            mp1[nums1[i]]++;
        }

        // Find the intersection elements
        for(int j = 0; j < m; j++) {
            if(mp1[nums2[j]] > 0) {
                res.push_back(nums2[j]);
                mp1[nums2[j]]--;
            }
        }

        return res;
    }
};
