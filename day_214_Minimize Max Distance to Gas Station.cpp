/*
Minimize Max Distance to Gas Station
Moderate
80/80
Contributed by
302 upvotes
Problem statement
You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis.



You are also given an integer ‘k’.



You have to place 'k' new gas stations on the X-axis.



You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions.



Let 'dist' be the maximum value of the distance between adjacent gas stations after adding 'k' new gas stations.

Find the minimum value of dist.


Example:
Input: ‘n' = 7 , ‘k’=6, ‘arr’ = {1,2,3,4,5,6,7}.

Answer: 0.5

Explanation:
We can place 6 gas stations at 1.5, 2.5, 3.5, 4.5, 5.5, 6.5. 

Thus the value of 'dist' will be 0.5. It can be shown that we can't get a lower value of 'dist' by placing 6 gas stations.


Note:
You will only see 1 or 0 in the output where:
  1 represents your answer is correct.
  0 represents your answer is wrong. 
Answers within 10^-6 of the actual answer will be accepted.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
5 4
1 2 3 4 5


Expected Answer:
0.5


Output Printed On Console:
1


Explanation of sample output 1:
k = 4, arr = {1,2,3,4,5} 

One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}

Thus the maximum difference between adjacent gas stations is 0.5. 

Hence, the value of ‘dist’ is 0.5. It can be shown that there is no possible way to add 4 gas stations in such a way that the value of ‘dist’ is lower than this. (Note: 1 will be printed in the output for the correct answer). 


Sample Input 2:
10 1
1 2 3 4 5 6 7 8 9 10


Expected Answer:
1


Output Printed On Console:
1


Explanation of sample output 2:
k = 1, arr = {1,2,3,4,5,6,7,8,9,10} 

One of the possible ways to place 1 gas station is {1,1.5,2,3,4,5,6,7,8,9,10} 

Thus the maximum difference between adjacent gas stations is still 1. 

Hence, the value of ‘dist’ is 1. It can be shown that there is no possible way to add 1 gas station in such a way that the value of ‘dist’ is lower than this. (Note: 1 will be printed in the output for the correct answer). 


Expected Time Complexity
Try solving this in O(n*log(A)), where A is the maximum value in array 'arr'.


Constraints:
2 <= n <= 10^5
1 <= k <= 10^6 
1 <= arr[i] <= 10^9

Time Limit: 1 sec
*/

/*
**Explanation:**
1. **Problem Statement:**
   - You are given an array `arr` of positions where gas stations are located along a highway. 
   - You need to add `k` additional gas stations such that the maximum distance between any two consecutive gas stations is minimized. 
   - Return the minimized maximum distance.

2. **Approach:**
   - **Priority Queue (Max-Heap):**
     - Use a max-heap (priority queue) to track the maximum distance between consecutive gas stations. 
     - For each interval between gas stations, keep track of how many additional stations have been added within that interval (`howMany` array).
   - **Simulation:**
     - Initially, push all intervals into the max-heap. The interval with the largest distance will be at the top.
     - For each new gas station to be added, remove the largest interval from the heap, divide it by the next increment (`howMany[secIdx] + 1`), and push the new interval back into the heap.
   - **Final Result:**
     - After all `k` gas stations have been added, the value at the top of the heap represents the minimized maximum distance.

3. **Time Complexity:**
   - The time complexity is O((n + k) log n), where `n` is the size of the array. The log factor arises from heap operations.

4. **Space Complexity:**
   - The space complexity is O(n) due to the auxiliary arrays and heap.

**Example Usage:**
- Given an array `arr = {1, 2, 8, 12}` and `k = 2`, the function returns the minimized maximum distance after placing two additional gas stations optimally.
*/

#include <bits/stdc++.h>
using namespace std;

double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> howMany(n-1, 0);  // Stores the number of additional stations in each interval.
	priority_queue<pair<long double, int>> pq;

	// Initial population of the heap with the initial differences between consecutive stations.
	for(int i = 0; i < n-1; i++){
		pq.push({arr[i+1] - arr[i], i});
	}

	// Distribute k gas stations across the intervals.
	for(int gasStation = 1; gasStation <= k; gasStation++){
		int secIdx = pq.top().second;
		pq.pop();
		howMany[secIdx]++;
		long double initDiff = arr[secIdx+1] - arr[secIdx];
		long double newDiff = initDiff / (long double)(howMany[secIdx] + 1);
		pq.push({newDiff, secIdx});
	}

	// The minimized maximum distance after placing k gas stations.
	return pq.top().first;
}

// Example usage:
int main() {
    vector<int> arr = {1, 2, 8, 12};
    int k = 2;
    cout << "Minimized maximum distance: " << minimiseMaxDistance(arr, k) << endl;
    return 0;
}


/*
**Explanation:**
1. **Problem Statement:**
   - You are given an array `arr` representing positions of gas stations on a highway. 
   - The goal is to minimize the maximum distance between any two consecutive gas stations by adding `k` additional gas stations.

2. **Approach:**
   - **Binary Search on Distance:**
     - The solution involves using binary search to determine the smallest possible maximum distance between consecutive gas stations after adding the `k` gas stations.
     - **Low** is initialized to 0, and **High** is initialized to the maximum distance between any two consecutive gas stations.
     - **Midpoint Calculation:** 
       - For each midpoint `mid`, the helper function `numberOfPossibleGasStation` calculates how many gas stations can be added if the maximum allowed distance between any two consecutive stations is `mid`.
       - If more than `k` gas stations are required to maintain this maximum distance, `low` is updated to `mid`, otherwise, `high` is updated to `mid`.
   - **Precision Handling:**
     - The loop continues until the difference between `low` and `high` is less than a small epsilon value `diff = 1e-6` to ensure sufficient precision.

3. **Time Complexity:**
   - The binary search runs in `O(log(high - low))`, and for each iteration, the `numberOfPossibleGasStation` function runs in `O(n)`.
   - The overall time complexity is `O(n log(high - low))`.

4. **Space Complexity:**
   - The space complexity is `O(1)` as we use only a few extra variables.

**Example Usage:**
- Given an array `arr = {1, 2, 8, 12}` and `k = 2`, the function returns the minimized maximum distance after placing two additional gas stations optimally.
*/

#include <bits/stdc++.h>
using namespace std;

// Helper function to calculate the number of gas stations that can be placed
// such that the maximum distance between any two consecutive stations does not exceed `dist`.
int numberOfPossibleGasStation(vector<int> &arr, long double dist) {
	int cnt = 0;
	int n = arr.size();
	for (int i = 1; i < n; i++) {
		int numberInBetween = (arr[i] - arr[i-1]) / dist;
		if ((arr[i] - arr[i-1]) / dist == numberInBetween * dist) {
			numberInBetween--;  // Adjust if the distance fits perfectly
		}
		cnt += numberInBetween;
	}
	return cnt;
}

// Function to minimize the maximum distance between any two consecutive gas stations after placing `k` new stations.
double minimiseMaxDistance(vector<int> &arr, int k) {
	int n = arr.size();
	long double low = 0;
	long double high = 0;
	for (int i = 1; i < n; i++) {
		high = max(high, (long double)(arr[i] - arr[i-1]));
	}	

	long double diff = 1e-6;

	// Perform binary search to find the smallest possible maximum distance.
	while (high - low > diff) {
		long double mid = (low + high) / 2.0;
		int cnt = numberOfPossibleGasStation(arr, mid);

		if (cnt > k) {
			low = mid;
		} else {
			high = mid;
		}
	}

	return high;  // The minimized maximum distance
}

// Example usage:
int main() {
    vector<int> arr = {1, 2, 8, 12};
    int k = 2;
    cout << "Minimized maximum distance: " << minimiseMaxDistance(arr, k) << endl;
    return 0;
}
