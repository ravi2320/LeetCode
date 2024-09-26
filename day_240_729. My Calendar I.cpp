/*
729. My Calendar I
Solved
Medium
Topics
Companies
Hint
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendar class:

MyCalendar() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 

Example 1:

Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]

Explanation
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.
 

Constraints:

0 <= start < end <= 109
At most 1000 calls will be made to book.
*/

/*
 * Approach:
 * 1. Use a set to keep track of booked intervals, represented as pairs of (start, end).
 * 2. For each new booking attempt, check if it overlaps with any existing interval in the set.
 * 3. Use `lower_bound` to find the first interval that starts after or at the same time as the new booking.
 * 4. Check for overlap with the next interval and the previous interval in the set:
 *    - If the new booking overlaps with the next interval (`itr->first < end`), return false.
 *    - If the new booking overlaps with the previous interval (`start < prevItr->second`), return false.
 * 5. If there is no overlap, insert the new interval into the set and return true.
 * 
 * Time Complexity: O(log N) for insertion and query in the set, where N is the number of booked intervals.
 * Space Complexity: O(N) to store the intervals in the set.
 */

class MyCalendar {
    set<pair<int, int>> st;  // Set to store intervals as (start, end)
public:
    // Constructor
    MyCalendar() {}

    // Function to book a new interval
    bool book(int start, int end) {
        // Find the first interval that starts after or at the same time as the current interval
        auto itr = st.lower_bound({start, end});
        
        // Check if the new interval overlaps with the next interval in the set
        if (itr != st.end() && itr->first < end) {
            return false;
        }

        // Check if the new interval overlaps with the previous interval in the set
        if (itr != st.begin()) {
            auto prevItr = prev(itr);
            if (start < prevItr->second) {
                return false;
            }
        }

        // If there is no overlap, insert the new interval into the set
        st.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start, end);
 */
