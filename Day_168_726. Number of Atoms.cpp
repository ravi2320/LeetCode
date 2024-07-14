/*
726. Number of Atoms
Solved
Hard
Topics
Companies
Hint
Given a string formula representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
Two formulas are concatenated together to produce another formula.

For example, "H2O2He3Mg4" is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula.

For example, "(H2O2)" and "(H2O2)3" are formulas.
Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.

 

Example 1:

Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.
Example 2:

Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
Example 3:

Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
 

Constraints:

1 <= formula.length <= 1000
formula consists of English letters, digits, '(', and ')'.
formula is always valid.
*/

/*
 * Intuition:
 * The problem involves parsing a chemical formula string and counting the number of each type of atom. The formula
 * can contain nested groups within parentheses, and these groups can be followed by a multiplier that applies to
 * all atoms in the group. To handle nested structures, we use a stack to maintain counts at each level of nesting.
 * 
 * Time Complexity: O(n * m log m), where n is the length of the formula and m is the number of unique elements.
 *   - Parsing the formula takes O(n).
 *   - Inserting into the sorted map and building the result string takes O(m log m).
 * Space Complexity: O(m), where m is the number of unique elements. This is due to the storage of atom counts.
 */

class Solution {
public:
    // Function to parse the formula and count atoms
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<unordered_map<string, int>> st; // Stack to handle nested parentheses
        st.push(unordered_map<string, int>());

        int i = 0;
        while (i < n) {
            if (formula[i] == '(') {
                st.push(unordered_map<string, int>()); // Start a new group
                i++;
            } else if (formula[i] == ')') {
                unordered_map<string, int> curr = st.top(); // Finish the current group
                st.pop();
                i++;

                string mult;
                while (i < n && isdigit(formula[i])) {
                    mult.push_back(formula[i]);
                    i++;
                }

                // Apply multiplier to the current group
                int multInteger = mult.empty() ? 1 : stoi(mult);
                for (auto &it : curr) {
                    string element = it.first;
                    int cnt = it.second;
                    curr[element] = cnt * multInteger;
                }

                // Merge the current group counts into the previous level
                for (auto &it : curr) {
                    string element = it.first;
                    int cnt = it.second;
                    st.top()[element] += cnt;
                }
            } else {
                string currElement;
                currElement.push_back(formula[i]);
                i++;

                // Read full element name
                while (i < n && isalpha(formula[i]) && islower(formula[i])) {
                    currElement.push_back(formula[i]);
                    i++;
                }

                // Read count for the current element
                string currCnt;
                while (i < n && isdigit(formula[i])) {
                    currCnt.push_back(formula[i]);
                    i++;
                }

                int currCntInteger = currCnt.empty() ? 1 : stoi(currCnt);
                st.top()[currElement] += currCntInteger; // Update the count for the current element
            }
        }

        // Sort elements lexicographically and build the result string
        map<string, int> sortMap(begin(st.top()), end(st.top()));
        string res = "";
        for (auto &it : sortMap) {
            string element = it.first;
            res += element;
            int cnt = it.second;
            if (cnt > 1) {
                res += to_string(cnt);
            }
        }

        return res;
    }
};
