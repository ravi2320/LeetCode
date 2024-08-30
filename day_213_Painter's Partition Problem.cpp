/*
Painter's Partition Problem
Moderate
80/80
Average time to solve is 25m
Contributed by
505 upvotes
Asked in companies
Problem statement
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.



You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.



Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2

Output: 11

Explanation:
First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
4 2
10 20 30 40


Sample Output 1 :
60


Explanation For Sample Input 1 :
In this test case, we can divide the first 3 boards for one painter and the last board for the second painter.


Sample Input 2 :
2 2
48 90


Sample Output 2 :
90


Expected Time Complexity:
Try to do this in O(n*log(n)).


Constraints :
1 <= n <= 10^5
1 <= k <= n
1 <= arr[i] <= 10^9

Time Limit: 1 sec.
*/

#include<bits/stdc++.h>
using namespace std;

/*
**Intuition:**
The problem requires dividing the board into sections to minimize the maximum workload any painter has to handle. This can be achieved by binary searching over the possible "maximum" workloads and determining the minimum feasible one.

**Approach:**
1. **Binary Search:**
   - Define the search space between the largest single board (`low`) and the sum of all board lengths (`high`).
   - For each midpoint (`mid`) of this range, determine the number of painters required if `mid` is the maximum load any painter can handle.
   - Adjust the search space based on whether the current number of painters exceeds the allowed number (`k`).

2. **Greedy Painter Assignment:**
   - In the helper function `findPainterCnt`, iterate through the boards, accumulating lengths until adding another board would exceed the current `mid` value, at which point assign a new painter.
   - This function returns the minimum number of painters required for the given `mid`.

**Time Complexity:** O(N * log(sum - max)), where `N` is the number of boards.
**Space Complexity:** O(1), except for input storage.

**Example Usage:**
- Given a list of board lengths and the number of painters, determine the minimum possible value of the maximum board length that any painter has to paint.
*/

int findPainterCnt(vector<int> &boards, int k, int maxLength) {
    int paintersCnt = 1;
    long long last = 0;

    for(int &boardLength : boards) {
        if(last + boardLength <= maxLength) {
            last += boardLength;
        } else {
            paintersCnt++;
            last = boardLength;
        }
    }

    return paintersCnt;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    long long low = *max_element(boards.begin(), boards.end());
    long long high = accumulate(boards.begin(), boards.end(), 0LL);  // Use 0LL to ensure sum is a long long

    while(low <= high) {
        int mid = (low + high) >> 1;
        int paintersCnt = findPainterCnt(boards, k, mid);

        if(paintersCnt <= k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

// Example usage
int main() {
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;  // Number of painters
    cout << "Minimum possible value of the maximum board length that any painter has to paint: " 
         << findLargestMinDistance(boards, k) << endl;

    return 0;
}
