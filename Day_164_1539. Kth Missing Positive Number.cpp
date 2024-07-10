/*
1539. Kth Missing Positive Number
Solved
Easy
Topics
Companies
Hint
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
arr[i] < arr[j] for 1 <= i < j <= arr.length
*/

/*
 * Intuition:
 * We need to find the k-th missing positive number from the given array `arr`.
 * We can iterate through the array and increment k whenever we encounter a number less than or equal to k.
 * This approach works because each such number means one less number before the k-th missing positive number.
 *
 * Time Complexity: O(n), where n is the size of the array.
 * Space Complexity: O(1), as we use a constant amount of extra space.
 */

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            if(arr[i] <= k)
                k++;
            else
                break;
        }

        return k;
    }
};

/*
 * Intuition:
 * We need to find the k-th missing positive number from the given array `arr`.
 * By using binary search, we can find the position where the k-th missing number would fit.
 * The number of missing numbers until index `mid` can be found using `arr[mid] - (mid + 1)`.
 * If this count is less than k, the missing number is further to the right; otherwise, it is to the left.
 *
 * Time Complexity: O(log n), where n is the size of the array, due to binary search.
 * Space Complexity: O(1), as we use a constant amount of extra space.
 */

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) { 
        int low = 0;
        int high = arr.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);

            if(missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high + k + 1;
    }
};
