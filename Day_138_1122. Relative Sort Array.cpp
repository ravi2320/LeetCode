/*
1122. Relative Sort Array
Solved
Easy
Topics
Companies
Hint
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
 

Constraints:

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.
*/

/*
Intuition:
- We are given two arrays, arr1 and arr2. The goal is to sort arr1 such that the relative ordering of the elements in arr1 are the same as those in arr2.
- Elements in arr1 that are not present in arr2 should be placed at the end of arr1 in ascending order.

Approach:
1. Use a map to count the frequency of each element in arr1.
2. Iterate through arr2, and for each element, place the corresponding number of elements in arr1 based on the frequency count in the map. Remove the element from the map once all instances are placed.
3. For the remaining elements in the map (those not in arr2), sort them and place them at the end of arr1.
4. Return the modified arr1.

Time Complexity: O(n log n)
- Counting frequencies takes O(n).
- Iterating through arr2 and arranging elements based on the map takes O(m) where m is the length of arr2.
- Placing remaining elements in sorted order takes O((n-m) log (n-m)), which in the worst case can be O(n log n).

Space Complexity: O(n)
- The map uses extra space proportional to the number of unique elements in arr1.

*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Step 1: Count frequencies of each element in arr1
        map<int, int> freqMap;
        for(int &num : arr1){
            freqMap[num]++;
        }   

        // Step 2: Place elements of arr2 in arr1 based on their frequency
        int i = 0;
        for(int &num : arr2){
            while(freqMap[num]--){
                arr1[i++] = num;
            }
            freqMap.erase(num);  // Remove the element from the map
        }

        // Step 3: Place remaining elements in sorted order
        for(auto &itr : freqMap){
            while(itr.second--){
                arr1[i++] = itr.first;
            }
        }

        return arr1;
    }
};
