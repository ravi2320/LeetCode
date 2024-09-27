/*
731. My Calendar II
Solved
Medium
Topics
Companies
Hint
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendarTwo class:

MyCalendarTwo() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.
 

Example 1:

Input
["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, true, true, true, false, true, true]

Explanation
MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
myCalendarTwo.book(10, 20); // return True, The event can be booked. 
myCalendarTwo.book(50, 60); // return True, The event can be booked. 
myCalendarTwo.book(10, 40); // return True, The event can be double booked. 
myCalendarTwo.book(5, 15);  // return False, The event cannot be booked, because it would result in a triple booking.
myCalendarTwo.book(5, 10); // return True, The event can be booked, as it does not use time 10 which is already double booked.
myCalendarTwo.book(25, 55); // return True, The event can be booked, as the time in [25, 40) will be double booked with the third event, the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
 

Constraints:

0 <= start < end <= 109
At most 1000 calls will be made to book.
*/

/*
 * Approach:
 * 1. Maintain two lists: `overallBookings` for all single bookings and `doubleBookingRegions` for double bookings (overlapping areas).
 * 2. To book a new event, check if it overlaps with any interval in `doubleBookingRegions`. If it does, reject the booking since it would cause a triple booking.
 * 3. If the booking passes, check its overlap with intervals in `overallBookings`. Any overlap is added to `doubleBookingRegions`.
 * 4. Finally, add the new booking to `overallBookings`.
 * 
 * Time Complexity: O(N), where N is the number of bookings made so far. Each booking involves checking overlaps.
 * Space Complexity: O(N), as it stores all intervals and double booking regions.
 */

class MyCalendarTwo {
    vector<pair<int, int>> overallBookings;       // Stores all single bookings
    vector<pair<int, int>> doubleBookingRegions;  // Stores regions of double bookings

public:
    MyCalendarTwo() {
        // Constructor initializes empty booking lists
    }
    
    bool book(int start, int end) {
        // Check for any overlap with existing double booking regions
        for (auto &region : doubleBookingRegions) {
            // If the current booking overlaps with a double booking region, reject it
            if (max(region.first, start) < min(region.second, end)) {
                return false;
            }
        }

        // Check overlap with single bookings to find double booking regions
        for (auto &region : overallBookings) {
            // If the current booking overlaps with a single booking, mark the overlapping region as double booking
            if (max(region.first, start) < min(region.second, end)) {
                doubleBookingRegions.push_back({max(region.first, start), min(region.second, end)});
            }
        }

        // Add the current booking to the list of overall bookings
        overallBookings.push_back({start, end});
        return true;  // Successfully booked without triple overlap
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start, end);
 */
