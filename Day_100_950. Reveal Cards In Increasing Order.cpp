/*
950. Reveal Cards In Increasing Order
Solved
Medium
Topics
Companies
You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].

You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.

You will do the following steps repeatedly until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, go back to step 1. Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

Note that the first entry in the answer is considered to be the top of the deck.

 

Example 1:

Input: deck = [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation: 
We get the deck in the order [17,13,11,2,3,5,7] (this order does not matter), and reorder it.
After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.
Example 2:

Input: deck = [1,1000]
Output: [1,1000]
 

Constraints:

1 <= deck.length <= 1000
1 <= deck[i] <= 106
All the values of deck are unique.
*/

// Intuition:
// 1. Sort the deck in increasing order.
// 2. Create a queue to keep track of the indices of cards to be revealed.
// 3. Initialize a result vector to store the revealed cards.
// 4. Iterate over the sorted deck:
//    a. Pop the front index from the queue and assign the corresponding card from the deck to the result vector.
//    b. If the queue is not empty, move the front index to the back of the queue.
// 5. Return the result vector.

// Time Complexity: O(nlogn) due to sorting, where n is the number of cards in the deck.
// Space Complexity: O(n) for the result vector and the queue.

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        // Sort the deck in increasing order
        sort(deck.begin(), deck.end());
        // Initialize result vector and queue
        vector<int> result(n, 0);
        queue<int> q;

        // Initialize the queue with indices
        for(int i=0; i<n; i++){
            q.push(i);
        }

        // Reveal the cards
        for(int i=0; i<n; i++){
            // Assign the card to the revealed position
            result[q.front()] = deck[i];
            q.pop();
            // Move the front index to the back of the queue if it's not empty
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }
};


// Intuition:
// 1. Sort the deck in increasing order.
// 2. Initialize a result vector to store the revealed cards.
// 3. Iterate through the result vector using a pointer 'i' to iterate through the sorted deck.
// 4. Iterate through the result vector using a pointer 'j' to determine the position to reveal the card.
// 5. When assigning a card to the position 'j', ensure that the previous position is empty and alternate between skipping and revealing cards.
// 6. Return the result vector.

// Time Complexity: O(nlogn) due to sorting, where n is the number of cards in the deck.
// Space Complexity: O(n) for the result vector.

#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        // Initialize result vector
        vector<int> res(n, 0);
        // Pointers for iterating through the sorted deck and determining the position to reveal the card
        int i = 0, j = 0;
        // Flag to skip positions
        bool skip = false;

        // Sort the deck in increasing order
        sort(deck.begin(), deck.end());

        // Iterate through the result vector
        while(i < n){
            // If the position 'j' is empty, assign a card from the sorted deck to it
            if(res[j] == 0){
                // If skip is false, reveal the card
                if(skip == false){
                    res[j] = deck[i];
                    i++;
                }
                // Alternate between skipping and revealing cards
                skip = !skip;
            }
            // Move to the next position in the result vector
            j = (j+1) % n;
        }
        
        return res;
    }
};
