/*
Delete middle element from stack
Easy
40/40
Average time to solve is 15m
Contributed by
208 upvotes
Asked in companies
Problem statement
You are having a stack "ARR" of size 'N+1', your task is to delete the middlemost element so that the size of resulting stack is 'N'.

A stack is a linear data structure where both insertion and deletion of elements take place at the top. It follows FILO (First In Last Out) or LIFO (Last In First Out) approaches. Books piled on top of each other is an example of a stack, where you can only remove a single book at a time, which is at the top of the stack. Likewise, you can only add a single book at a time, on the top of the stack only.

Example :-
INPUT : ARR [ ] = [ 1 , 2 , 3 , 4 , 5 ] , N = 4
OUTPUT: ARR [ ] = [ 1 , 2 , 4,  5 ]

The above example contains an odd number of elements, hence the middle element is clearly the (N+1) / 2th element, which is removed from the stack in the output.

INPUT : ARR [ ] = [ 5, 6, 7, 8 ] , N = 3
OUTPUT: ARR [ ] = [ 5, 7, 8 ]

The above example contains an even number of elements, so out of the two middle elements, we consider the one which occurs first. Hence, the middle element would be ((N+1) / 2 - 1) element, which is 6 and is removed from the stack in the output.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100    
1 <= N+1 <= 3000
0 <= data <= 10^9

Where ‘T’ is the number of test cases, ‘N+1’ is the number of elements in the input Stack. ‘data’ is the value of each element in the stack.

Time limit: 1 second
Sample Input 1:
2
4
1 2 3 4 5
7
83 74 67 49 94 8 11 1
Sample Output 1:
1 2 4 5
83 74 67 94 8 11 1
Explanation for Sample 1:
In the 1st testcase, there are an odd number of elements, hence the middle element is clearly the (N+1) / 2th element which is 3, and is removed from the stack in the output.

In the 2nd testcase, there are an odd number of elements, hence the middle element is clearly the (N+1) / 2th element which is 49, and is removed from the stack in the output.
Sample Input 2:
3
1
5 10    
4
1 3 4 2 7
5
9 5 2 7 8 6
Sample Output 2:
10
1 3 2 7
9 5 7 8 6
*/

/*
Approach:
- The goal is to delete the middle element from the stack. Given that the stack follows Last In First Out (LIFO) order, direct access to the middle element is not possible.
- The solution involves using recursion to reach the middle element, remove it, and then restore the rest of the stack.
  
Steps:
1. Define a helper function `solve` to recursively remove the top elements of the stack until the middle element is reached.
2. Once at the middle, remove the middle element using `pop()`.
3. As the recursion backtracks, push back the elements in the correct order to restore the stack.

Time Complexity:
- O(N), where `N` is the number of elements in the stack. This is because we need to pop all elements up to the middle and push them back.

Space Complexity:
- O(N), due to the recursive call stack.

*/

#include <bits/stdc++.h>
using namespace std;

// Recursive function to remove the middle element
void solve(stack<int>& inputStack, int cnt, int N) {
    // Base case: if we have reached the middle, remove the element
    if (cnt == N / 2) {
        inputStack.pop();  // Remove the middle element
        return;
    }

    // Store the current top element and remove it
    int num = inputStack.top();
    inputStack.pop();

    // Recursive call to remove the next element
    solve(inputStack, cnt + 1, N);

    // Push the element back after removing the middle
    inputStack.push(num);
}

// Function to delete the middle element from the stack
void deleteMiddle(stack<int>& inputStack, int N) {
    solve(inputStack, 0, N);  // Start the recursion from the first element
}