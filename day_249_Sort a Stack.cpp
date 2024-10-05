/*
Sort a Stack
Easy
40/40
Average time to solve is 10m
Contributed by
429 upvotes
Asked in companies
Problem statement
You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.

We can only use the following functions on this stack S.

is_empty(S) : Tests whether stack is empty or not.
push(S) : Adds a new element to the stack.
pop(S) : Removes top element from the stack.
top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.
Note :
1) Use of any loop constructs like while, for..etc is not allowed. 
2) The stack may contain duplicate integers.
3) The stack may contain any integer i.e it may either be negative, positive or zero.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'T' <= 100
1 <=  'N' <= 100
1 <= |'V'| <= 10^9

Where |V| denotes the absolute value of any stack element.

Time limit: 1 sec
Sample Input 1:
1
5
5 -2 9 -7 3
Sample Output 1:
9 5 3 -2 -7
Explanation of Sample Input 1:
9 Is the largest element, hence it’s present at the top. Similarly 5>3, 3>-2 and -7 being the smallest element is present at the last. 
Sample Input 2:
1
5
-3 14 18 -5 30
Sample Output 2:
30 18 14 -3 -5
Explanation of Sample Input 2:
30 is the largest element, hence it’s present at the top. Similarly, 18>14, 14>-3 and -5 being the smallest element is present at the last. 
*/

/*
Approach:
1. **Recursive Sort**:
   - The function `sortStack` uses recursion to sort a stack.
   - It removes the top element of the stack and calls itself recursively to sort the remaining stack.
   - After the recursive call returns, the removed top element is inserted back into the stack in its correct position using the helper function `addTopInSortedOrder`.

2. **Insert in Sorted Order**:
   - The helper function `addTopInSortedOrder` inserts an element into the correct position in an already sorted stack.
   - It recursively pops elements from the stack until the correct position is found, then pushes the current element and restores the previously popped elements.

Time Complexity:
- The time complexity is **O(n^2)**, where `n` is the number of elements in the stack. Each recursive call requires an additional pass to insert the elements back in sorted order.

Space Complexity:
- The space complexity is **O(n)** due to the recursive call stack.

*/

#include <bits/stdc++.h> 

// Function to add the element at the correct sorted position in the stack
void addTopInSortedOrder(stack<int> &stack, int num) {
    // Base case: if stack is empty or top element is smaller than num, push num
    if (stack.empty() || stack.top() < num) {
        stack.push(num);
        return;
    }

    // Recursively pop elements to find the correct position for num
    int top = stack.top();
    stack.pop();

    // Call recursively to find the position for num
    addTopInSortedOrder(stack, num);

    // Push the previously popped elements back after num is placed
    stack.push(top);
}

// Function to sort the stack recursively
void sortStack(stack<int> &stack) {
    // Base case: If stack is empty, return
    if (stack.empty()) {
        return;
    }

    // Pop the top element and sort the remaining stack
    int top = stack.top();
    stack.pop();

    // Recursive call to sort the rest of the stack
    sortStack(stack);

    // Insert the popped element back in the correct sorted order
    addTopInSortedOrder(stack, top);
}
