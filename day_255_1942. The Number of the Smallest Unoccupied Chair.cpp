/*
1942. The Number of the Smallest Unoccupied Chair
Solved
Medium
Topics
Companies
Hint
There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.

For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on.

 

Example 1:

Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
Output: 1
Explanation: 
- Friend 0 arrives at time 1 and sits on chair 0.
- Friend 1 arrives at time 2 and sits on chair 1.
- Friend 1 leaves at time 3 and chair 1 becomes empty.
- Friend 0 leaves at time 4 and chair 0 becomes empty.
- Friend 2 arrives at time 4 and sits on chair 0.
Since friend 1 sat on chair 1, we return 1.
Example 2:

Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
Output: 2
Explanation: 
- Friend 1 arrives at time 1 and sits on chair 0.
- Friend 2 arrives at time 2 and sits on chair 1.
- Friend 0 arrives at time 3 and sits on chair 2.
- Friend 1 leaves at time 5 and chair 0 becomes empty.
- Friend 2 leaves at time 6 and chair 1 becomes empty.
- Friend 0 leaves at time 10 and chair 2 becomes empty.
Since friend 0 sat on chair 2, we return 2.
 

Constraints:

n == times.length
2 <= n <= 104
times[i].length == 2
1 <= arrivali < leavingi <= 105
0 <= targetFriend <= n - 1
Each arrivali time is distinct.
*/

/*
Approach:
1. **Sorting by Arrival Time**: We first sort the `times` array by the arrival time to handle each friend's arrival in chronological order.
2. **Simulating Chair Assignment**: We maintain an array `chairs` to track when each chair becomes available.
   - When a person arrives, we check for the smallest available chair (a chair whose previous occupant has left).
   - If the chair is available (i.e., its departure time is <= the current person's arrival time), we assign it to the current person.
   - If the current person is the `targetFriend`, we return the chair number assigned.
3. **Time Complexity**:
   - Sorting the `times` array takes **O(n log n)**, where `n` is the number of friends.
   - The rest of the process involves checking for available chairs, which takes **O(n^2)** in the worst case if there are `n` friends and we loop over all chairs for each arrival.
4. **Space Complexity**: **O(n)** for the `chairs` array to track the availability of each chair.

*/

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();  // Number of friends

        vector<int> chairs(n, -1);  // Track chair availability (when each chair becomes available)

        // Store the arrival time of the target friend
        int targetFriendArrivalTime = times[targetFriend][0];

        // Sort times by arrival time
        sort(times.begin(), times.end());

        // Process each friend's arrival and departure time
        for(auto &time : times) {
            int arrivalTime = time[0];
            int departureTime = time[1];

            // Find the smallest available chair
            for(int i = 0; i < n; i++) {
                if(chairs[i] <= arrivalTime) {  // If chair i is available
                    chairs[i] = departureTime;  // Assign the chair and update its availability

                    // If this is the target friend's arrival time, return the chair number
                    if(arrivalTime == targetFriendArrivalTime) {
                        return i;
                    }
                    break;  // Move to the next friend
                }
            }
        }

        return -1;  // Return -1 if no chair is found (this case shouldn't occur in valid input)
    }
};

/*
Approach:
1. **Priority Queues**:
   - `occupied`: A min-heap that stores pairs of departure time and chair number (sorted by earliest departure).
   - `free`: A min-heap that stores available chair numbers (sorted by smallest chair number).
   - As friends arrive, we assign the smallest available chair. When a friend leaves (based on departure time), their chair becomes available and is pushed into `free`.
2. **Sorting**: First, sort the friends by their arrival times.
3. **Chair Assignment**: For each arrival, check if any chairs are freed (i.e., friends leave before or when the new friend arrives). Assign the smallest available chair to the arriving friend.
4. **Target Friend**: If the current arrival is the `targetFriend`, return the chair assigned to them.
5. **Time Complexity**:
   - Sorting the `times` array takes **O(n log n)**.
   - Using priority queues for chair assignment takes **O(n log n)** for each operation, as both `occupied` and `free` operate in **O(log n)** time.
   - Overall time complexity is **O(n log n)**.
6. **Space Complexity**: **O(n)** for the two priority queues and the storage of the `times` array.

*/

class Solution {
    typedef pair<int, int> P;  // Pair to store (departure time, chair number)
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        // Min-heap to track currently occupied chairs by earliest departure time
        priority_queue<P, vector<P>, greater<P>> occupied;

        // Min-heap to track available chairs by chair number (smallest first)
        priority_queue<int, vector<int>, greater<int>> free;

        // Store the target friend's arrival time
        int targetFriendArrivalTime = times[targetFriend][0];
        int chair = 0;  // To assign new chairs when no chairs are free

        // Sort friends by their arrival times
        sort(times.begin(), times.end());

        // Iterate through the sorted arrival times
        for (int i = 0; i < n; i++) {
            int arrival = times[i][0];
            int departure = times[i][1];

            // Free up chairs if friends have left before or at the current friend's arrival time
            while (!occupied.empty() && occupied.top().first <= arrival) {
                free.push(occupied.top().second);  // The chair is now free
                occupied.pop();  // Remove the friend who left
            }

            // If there are no free chairs, assign a new chair
            if (free.empty()) {
                occupied.push({departure, chair});  // Occupy a new chair
                
                // Check if the current friend is the target friend
                if (arrival == targetFriendArrivalTime) {
                    return chair;  // Return the chair number assigned to the target friend
                }
                chair++;  // Increment to assign the next new chair
            }
            // If there are free chairs, assign the smallest available chair
            else {
                occupied.push({departure, free.top()});  // Use the smallest available chair

                // Check if the current friend is the target friend
                if (arrival == targetFriendArrivalTime) {
                    return free.top();  // Return the chair number assigned to the target friend
                }
                
                free.pop();  // Remove the chair from the free list
            }
        }

        return -1;  // In case no chair is found (this case shouldn't happen with valid input)
    }
};