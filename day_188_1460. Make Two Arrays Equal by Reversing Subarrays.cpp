/*
1460. Make Two Arrays Equal by Reversing Subarrays
Solved
Easy
Topics
Companies
Hint
You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.

Return true if you can make arr equal to target or false otherwise.

 

Example 1:

Input: target = [1,2,3,4], arr = [2,4,1,3]
Output: true
Explanation: You can follow the next steps to convert arr to target:
1- Reverse subarray [2,4,1], arr becomes [1,4,2,3]
2- Reverse subarray [4,2], arr becomes [1,2,4,3]
3- Reverse subarray [4,3], arr becomes [1,2,3,4]
There are multiple ways to convert arr to target, this is not the only way to do so.
Example 2:

Input: target = [7], arr = [7]
Output: true
Explanation: arr is equal to target without any reverses.
Example 3:

Input: target = [3,7,9], arr = [3,7,11]
Output: false
Explanation: arr does not have value 9 and it can never be converted to target.
 

Constraints:

target.length == arr.length
1 <= target.length <= 1000
1 <= target[i] <= 1000
1 <= arr[i] <= 1000
*/

/*
Intuition:
The problem requires determining if we can make two arrays equal by rearranging one of them. By sorting both arrays, we can compare them directly to check if they contain the same elements.

Time Complexity:
The time complexity is O(n log n) due to the sorting of both arrays, where n is the number of elements in the arrays.

Space Complexity:
The space complexity is O(1) if we consider the sort operations to be in-place.

*/

class Solution {
public:
    // Function to check if the two arrays can be made equal by sorting
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();

        // Sort both arrays
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        // Compare the sorted arrays
        for(int i = 0; i < n; i++) {
            if(arr[i] != target[i]) {
                return false; // Arrays are not equal
            }
        }

        return true; // Arrays are equal
    }
};


/*
Intuition:
To determine if two arrays can be made equal by rearranging one of them, we can use a hashmap (unordered_map) to count the occurrences of each element in one array and then decrement the counts based on the elements in the other array. If the hashmap is empty at the end, it means both arrays can be made equal.

Time Complexity:
The time complexity is O(n) since we are traversing both arrays once, where n is the number of elements in the arrays.

Space Complexity:
The space complexity is O(n) due to the storage required for the hashmap.

*/

class Solution {
public:
    // Function to check if the two arrays can be made equal using a hashmap
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // Create a hashmap to count the occurrences of elements in the target array
        unordered_map<int, int> mp;
        
        // Increment the count of each element in the target array
        for(int &x : target) {
            mp[x]++;
        }

        // Decrement the count of each element in the arr array
        for(int &x : arr) {
            // If the element is not found in the hashmap, return false
            if(mp.find(x) == mp.end()) {
                return false;
            }
            // Decrement the count of the element
            mp[x]--;
            // If the count reaches zero, erase the element from the hashmap
            if(mp[x] == 0) {
                mp.erase(x);
            }
        }

        // If the hashmap is empty, it means both arrays can be made equal
        return mp.empty();
    }
};
