/*
869. Reordered Power of 2

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

 

Example 1:

Input: n = 1
Output: true
Example 2:

Input: n = 10
Output: false
 

Constraints:

1 <= n <= 109
*/

/*
Approach:
1. Convert the given integer `n` into a string and sort its digits to form a canonical representation.
2. Precompute all possible powers of 2 (from 2^0 to 2^29) since the constraint is within 32-bit integers.
3. For each power of 2, sort its digits and compare with the sorted digits of `n`.
4. If any match is found, return true; otherwise return false.

Intuition:
- Two numbers are permutations of each other if they have the same digits in the same frequency.
- Sorting the digits creates a normalized form that makes comparison easy.
- Since there are very few powers of 2 within integer range (only 30), iterating through all is efficient.

Time Complexity:
- Sorting digits of a number: O(log n * log log n) where log n is the number of digits.
- We do this for at most 30 numbers → O(30 * log n * log log n) ≈ O(1) in practical terms.
Space Complexity:
- O(log n) for storing the string representation of the number.
*/

class Solution {
public:
    // Helper function to convert number to sorted string of its digits
    string getSorted(int n) {
        string s = to_string(n);     // Convert number to string
        sort(s.begin(), s.end());    // Sort digits
        return s;                    // Return sorted form
    }

    bool reorderedPowerOf2(int n) {
        string s = getSorted(n);     // Get sorted digits of input number

        // Loop over all powers of 2 within 32-bit integer range
        for (int p = 0; p <= 29; p++) {
            if (s == getSorted(1 << p)) { // Compare with sorted digits of current power of 2
                return true;              // Found a match
            }
        }
        return false; // No match found
    }
};


/*
Approach:
1. Precompute all powers of 2 up to 2^29 (since 2^30 exceeds the 10^9 limit for int).
2. Convert each power of 2 into a string, sort its digits, and store it in a hash set.
3. For the given number n, convert it into a string, sort its digits, and check if it exists in the precomputed set.
4. If found, it means n can be rearranged to form a power of 2.

Intuition:
Any number can be rearranged to match a power of 2 if its digit multiset (sorted digits) matches that of a power of 2.
By precomputing sorted digit patterns for all powers of 2, we can quickly check membership for any given number.

Time Complexity:
- Precomputation: O(30 * k log k) where k ≤ 10 (max digits in 2^29).
- Query: O(k log k) for sorting digits of n.
Overall: O(1) amortized per query after precomputation.
Space Complexity: O(30 * k) for storing sorted digit strings in the set.
*/

class Solution {
    unordered_set<string> st; // Stores sorted digit patterns of powers of 2
    
public:
    // Precompute all sorted digit strings for powers of 2 up to 2^29
    void buildSet() {
        for (int p = 0; p <= 29; p++) {  
            string num = to_string(1 << p); // Convert power of 2 to string
            sort(num.begin(), num.end());  // Sort digits
            st.insert(num);                // Store in set
        }
    }

    bool reorderedPowerOf2(int n) {
        // Build set only once for efficiency
        if (st.empty()) {
            buildSet();
        }

        string s = to_string(n);   // Convert n to string
        sort(s.begin(), s.end()); // Sort digits
        
        return st.count(s);       // Check if sorted pattern exists in set
    }
};

																					
/*
Approach:
1. **Digit Frequency Representation**:
   - Convert the given integer `n` into a frequency vector of size 10, 
     where each index represents a digit (0–9) and the value is the count of that digit.
   - This helps us compare numbers based on the digits they contain, regardless of order.

2. **Check Against Powers of 2**:
   - Iterate over all powers of 2 from `2^0` to `2^29` (since `2^30` exceeds 10 digits for int range).
   - For each power of 2, generate its digit frequency vector and compare with the input's vector.
   - If they match, it means that `n` can be reordered to form that power of 2.

3. **Return Result**:
   - If a match is found, return true; otherwise, return false.

Intuition:
- Numbers with the same digits in different orders have the same digit frequency.
- Instead of checking all permutations (which is costly), 
  just check if the digit frequency matches any power of 2's frequency.

Time Complexity:
- `getVectorCount` runs in O(log₁₀n) for digit extraction.
- We check at most 30 powers of 2.
- Overall: **O(30 × log₁₀n) ≈ O(log n)** (very efficient).

Space Complexity:
- O(1) extra space (only frequency arrays of size 10 are used).

*/

class Solution {
public:
    // Function to generate a digit frequency vector for a given number
    vector<int> getVectorCount(int n) {
        vector<int> freq(10, 0); // 10 slots for digits 0–9
        
        while (n) {  
            freq[n % 10]++; // Increment frequency for the last digit
            n /= 10;        // Remove last digit
        }
        
        return freq;
    }

    bool reorderedPowerOf2(int n) {
        // Get digit frequency for the input number
        vector<int> input = getVectorCount(n);

        // Check against all possible powers of 2 within 32-bit integer range
        for (int p = 0; p <= 29; p++) {
            // If digit frequency matches any power of 2, return true
            if (input == getVectorCount(1 << p)) {
                return true;
            }
        }

        // If no match found, return false
        return false;
    }
};