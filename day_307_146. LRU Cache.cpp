/*
146. LRU Cache
Solved
Medium
Topics
Companies
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
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
