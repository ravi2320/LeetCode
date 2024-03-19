/*
621. Task Scheduler
Solved
Medium
Topics
Companies
You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.

​Return the minimum number of intervals required to complete all tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two cycles before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th cycle, you can do A again as 2 intervals have passed.

Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1

Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:

Input: tasks = ["A","A","A", "B","B","B"], n = 3

Output: 10

Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

 

Constraints:

1 <= tasks.length <= 104
tasks[i] is an uppercase English letter.
0 <= n <= 100
*/

// Approach:
// - We first count the frequency of each task using a frequency map.
// - We then push the frequencies into a max heap (priority_queue) to process tasks with the highest frequency first.
// - We iterate through the tasks, processing them in chunks of (n+1) tasks, where n is the cooldown period.
// - For each chunk, we pop tasks from the priority queue, decrement their frequencies, and add them back if they still have remaining tasks.
// - If the priority queue becomes empty during processing, we add the remaining tasks in the current chunk to the total time.
// - Otherwise, we add the entire cooldown period (n+1) to the total time for the next iteration.
// - Finally, we return the total time taken to complete all tasks.

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        // Count the frequency of each task
        vector<int> mp(26, 0);
        for(char ch : tasks)
            mp[ch - 'A']++;

        // Priority queue to process tasks with highest frequency first
        priority_queue<int> pq;
        for(int i=0; i<26; i++){
            if(mp[i] > 0)
                pq.push(mp[i]);
        }
        
        int time = 0;
        // Process tasks until the priority queue is empty
        while(!pq.empty()){
            // Temporary vector to store frequencies of tasks in the current chunk
            vector<int> temp;
            // Process a chunk of (n+1) tasks
            for(int i=1; i<= n+1; i++){
                // If priority queue is not empty, pop a task, decrement its frequency, and add it to the temporary vector
                if(!pq.empty()){    
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            // Add back tasks with remaining frequency to the priority queue
            for(int f : temp){
                if(f > 0){
                    pq.push(f);
                }
            }

            // If priority queue is empty, add the remaining tasks in the current chunk to the total time
            if(pq.empty())
                time += temp.size();
            // Otherwise, add the entire cooldown period (n+1) to the total time for the next iteration
            else
                time += n+1;
        }
        return time;
    }
};
