/*
2054. Two Best Non-Overlapping Events
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

 

Example 1:


Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
Example 2:

Example 1 Diagram
Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.
Example 3:


Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
 

Constraints:

2 <= events.length <= 105
events[i].length == 3
1 <= startTimei <= endTimei <= 109
1 <= valuei <= 106
*/

/*
Approach:
1. **Doubly Linked List**:
   - Use a doubly linked list to maintain the order of keys based on their access frequency (most recently used at the head).

2. **Hash Map**:
   - Use an unordered map for O(1) access to nodes in the linked list.

3. **Put Operation**:
   - If the key already exists, remove the node and update it with the new value at the head of the list.
   - If the cache is full, remove the least recently used (LRU) node (from the tail) before adding the new key.

4. **Get Operation**:
   - If the key exists, move the corresponding node to the head to mark it as recently used and return its value.
   - Otherwise, return -1.

Time Complexity:
- **O(1)** for both `get` and `put` operations due to the combined use of the hash map and doubly linked list.

Space Complexity:
- **O(capacity)** for the hash map and doubly linked list.

*/

class LRUCache {
public:
    // Node structure for the doubly linked list
    class node {
    public:
        int key, val;
        node* next;
        node* prev;
        node(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {}
    };

    node* head; // Dummy head for the doubly linked list
    node* tail; // Dummy tail for the doubly linked list
    int cap;    // Capacity of the cache
    unordered_map<int, node*> m; // Hash map for O(1) access to nodes

    // Constructor
    LRUCache(int capacity) {
        cap = capacity;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Helper to add a node after the head
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    // Helper to delete a node
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    // Get the value of the key if it exists
    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node* resnode = m[key_];
            int res = resnode->val;
            m.erase(key_); // Remove the key from the map
            deletenode(resnode); // Remove the node from the list
            addnode(resnode);    // Add the node to the front
            m[key_] = head->next; // Update the map with the new head
            return res;
        }
        return -1; // Key not found
    }

    // Put a key-value pair in the cache
    void put(int key_, int value) {
        if (m.find(key_) != m.end()) {
            node* existingnode = m[key_];
            m.erase(key_); // Remove the key from the map
            deletenode(existingnode); // Delete the existing node
        }
        if (m.size() == cap) {
            m.erase(tail->prev->key); // Remove the LRU key
            deletenode(tail->prev);   // Remove the LRU node
        }
        addnode(new node(key_, value)); // Add the new node to the front
        m[key_] = head->next; // Update the map
    }
};
