/*
432. All O`one Data Structure
Solved
Hard
Topics
Companies
Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
Note that each function must run in O(1) average time complexity.

 

Example 1:

Input
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
Output
[null, null, null, "hello", "hello", null, "hello", "leet"]

Explanation
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "hello"
allOne.inc("leet");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "leet"
 

Constraints:

1 <= key.length <= 10
key consists of lowercase English letters.
It is guaranteed that for each call to dec, key is existing in the data structure.
At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.
*/

/*
 * Approach:
 * - This class maintains a data structure to track string counts and supports the following operations:
 *   1. `inc(key)` - Increment the count of a given key.
 *   2. `dec(key)` - Decrement the count of a given key.
 *   3. `getMaxKey()` - Return a key with the maximum count.
 *   4. `getMinKey()` - Return a key with the minimum count.
 * 
 * Key Ideas:
 * - We use a doubly linked list to keep track of groups of keys with the same count, each node
 *   representing a group of keys with a certain count.
 * - An unordered map (`mp`) maps each key to its corresponding node in the linked list.
 * - Each linked list node holds a set of keys with the same count and pointers to the previous and next nodes.
 * 
 * Time Complexity:
 * - `inc(key)` and `dec(key)` operations: O(1) amortized time due to unordered set and list operations.
 * - `getMaxKey()` and `getMinKey()` operations: O(1) time as we simply access the head or tail.
 * 
 * Space Complexity:
 * - O(n), where `n` is the number of unique keys stored in the structure.
 */

class AllOne {
private:
    // Doubly Linked List node to store count and a set of strings with that count
    struct Node {
        int count; // The count of the keys in this node
        list<string> keys; // List of keys that have the same count
        Node *prev, *next; // Pointers to previous and next nodes in the doubly linked list

        Node(int c) : count(c), prev(nullptr), next(nullptr) {} // Constructor to initialize the node with a given count
    };

    // Hash map to store key -> count (i.e., each key maps to its corresponding node)
    unordered_map<string, Node*> mp;

    // Head and tail pointers for the doubly linked list (dummy nodes)
    Node *head, *tail;

    // Add a new node with count `c` after node `prevNode`
    Node* addNodeAfter(Node *prevNode, int count) {
        Node *newNode = new Node(count); // Create a new node with the given count
        newNode->next = prevNode->next; // Link the new node to the next node in the list
        newNode->prev = prevNode; // Link the new node to the previous node
        if (prevNode->next) {
            prevNode->next->prev = newNode; // Update the previous pointer of the next node
        }
        prevNode->next = newNode; // Update the next pointer of the previous node
        if (tail == prevNode) {
            tail = newNode; // Update the tail if we added the node at the end of the list
        }
        return newNode; // Return the new node
    }

    // Remove the node from the doubly linked list
    void removeNode(Node *node) {
        node->prev->next = node->next; // Update the next pointer of the previous node
        if (node->next) {
            node->next->prev = node->prev; // Update the previous pointer of the next node
        }
        if (tail == node) {
            tail = node->prev; // Update the tail if we removed the last node
        }
        delete node; // Free memory
    }

public:
    AllOne() {
        // Initialize head and tail dummy nodes for the doubly linked list
        head = new Node(0); // The head node is a dummy node with count 0
        tail = head; // Initially, the head and tail are the same
    }

    void inc(string key) {
        if (mp.find(key) == mp.end()) {
            // Key doesn't exist, add it to the list after the head with count 1
            if (head->next == nullptr || head->next->count != 1) {
                addNodeAfter(head, 1); // Add a new node with count 1 after the head
            }
            head->next->keys.push_front(key); // Add the key to the node with count 1
            mp[key] = head->next; // Map the key to this node
        } else {
            // Key exists, move it to the next count
            Node *curNode = mp[key]; // Get the current node
            int curCount = curNode->count; // Get the current count
            if (curNode->next == nullptr || curNode->next->count != curCount + 1) {
                addNodeAfter(curNode, curCount + 1); // Add a new node with the next count if it doesn't exist
            }
            curNode->next->keys.push_front(key); // Move the key to the node with the next count
            mp[key] = curNode->next; // Update the map to reflect the new count
            curNode->keys.remove(key); // Remove the key from the current node
            if (curNode->keys.empty()) {
                removeNode(curNode); // Remove the node if it has no more keys
            }
        }
    }

    void dec(string key) {
        Node *curNode = mp[key]; // Get the current node
        int curCount = curNode->count; // Get the current count
        
        // Remove the key if count becomes zero
        curNode->keys.remove(key); // Remove the key from the current node
        if (curCount == 1) {
            mp.erase(key); // Erase the key from the map if its count is 1
        } else {
            // Move it to the previous count
            if (curNode->prev == head || curNode->prev->count != curCount - 1) {
                addNodeAfter(curNode->prev, curCount - 1); // Add a new node with the previous count if it doesn't exist
            }
            curNode->prev->keys.push_front(key); // Move the key to the previous count
            mp[key] = curNode->prev; // Update the map
        }
        
        // Remove the current node if it has no more keys
        if (curNode->keys.empty()) {
            removeNode(curNode); // Remove the node if it's empty
        }
    }

    string getMaxKey() {
        return (tail == head) ? "" : tail->keys.front(); // Return the key with the maximum count, or an empty string if none exist
    }

    string getMinKey() {
        return (head->next == nullptr) ? "" : head->next->keys.front(); // Return the key with the minimum count, or an empty string if none exist
    }
};
