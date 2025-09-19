/*
3484. Design Spreadsheet

A spreadsheet is a grid with 26 columns (labeled from 'A' to 'Z') and a given number of rows. Each cell in the spreadsheet can hold an integer value between 0 and 105.

Implement the Spreadsheet class:

Spreadsheet(int rows) Initializes a spreadsheet with 26 columns (labeled 'A' to 'Z') and the specified number of rows. All cells are initially set to 0.
void setCell(String cell, int value) Sets the value of the specified cell. The cell reference is provided in the format "AX" (e.g., "A1", "B10"), where the letter represents the column (from 'A' to 'Z') and the number represents a 1-indexed row.
void resetCell(String cell) Resets the specified cell to 0.
int getValue(String formula) Evaluates a formula of the form "=X+Y", where X and Y are either cell references or non-negative integers, and returns the computed sum.
Note: If getValue references a cell that has not been explicitly set using setCell, its value is considered 0.

 

Example 1:

Input:
["Spreadsheet", "getValue", "setCell", "getValue", "setCell", "getValue", "resetCell", "getValue"]
[[3], ["=5+7"], ["A1", 10], ["=A1+6"], ["B2", 15], ["=A1+B2"], ["A1"], ["=A1+B2"]]

Output:
[null, 12, null, 16, null, 25, null, 15]

Explanation

Spreadsheet spreadsheet = new Spreadsheet(3); // Initializes a spreadsheet with 3 rows and 26 columns
spreadsheet.getValue("=5+7"); // returns 12 (5+7)
spreadsheet.setCell("A1", 10); // sets A1 to 10
spreadsheet.getValue("=A1+6"); // returns 16 (10+6)
spreadsheet.setCell("B2", 15); // sets B2 to 15
spreadsheet.getValue("=A1+B2"); // returns 25 (10+15)
spreadsheet.resetCell("A1"); // resets A1 to 0
spreadsheet.getValue("=A1+B2"); // returns 15 (0+15)
 

Constraints:

1 <= rows <= 103
0 <= value <= 105
The formula is always in the format "=X+Y", where X and Y are either valid cell references or non-negative integers with values less than or equal to 105.
Each cell reference consists of a capital letter from 'A' to 'Z' followed by a row number between 1 and rows.
At most 104 calls will be made in total to setCell, resetCell, and getValue.
*/

/*
Approach:
1. We maintain a 2D matrix `matrix[rows][26]` to represent spreadsheet cells
   (row-indexed, 26 fixed columns for A-Z).
2. `setCell(cell, value)`:
   - Convert column letter (A-Z) and row number into indices.
   - Update matrix[row][col] with the given value.
3. `resetCell(cell)`:
   - Set the value at the given row/col to 0.
4. `getNum(idx, formula)`:
   - Parse a number starting from index `idx` in the formula string.
5. `getFormulaValue(i, formula)`:
   - If the token starts with A-Z, it's a cell reference → look up its value.
   - Else, parse it as a number.
6. `getValue(formula)`:
   - Parse the formula string.
   - Start after '=' and repeatedly evaluate terms separated by '+'.
   - Return the sum of all evaluated values.

Intuition:
- The problem simulates a mini Excel-like system.
- Cell values are stored in a 2D array.
- Formulas are parsed manually:
  - `=A1+5+B2` → look up A1, add 5, add B2.
- The system supports both constants and cell references.

Time Complexity:
- `setCell`, `resetCell`: O(1) (direct assignment).
- `getValue`: O(L) where L = length of the formula string.
- `getFormulaValue`: O(1) per token lookup.
So overall, evaluating a formula is linear in its length.

Space Complexity: O(R * 26)
- R = number of rows.
- Fixed 26 columns.
- Plus O(1) extra parsing variables.

*/

class Spreadsheet {
    vector<vector<int>> matrix; // stores values for each cell
public:
    // Initialize spreadsheet with 'rows' rows and 26 columns (A-Z)
    Spreadsheet(int rows) {
        matrix.resize(rows, vector<int>(26, 0));
    }
    
    // Set cell value like A1, B2, etc.
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';             // extract column
        int row = stoi(cell.substr(1)) - 1;  // extract row (1-based → 0-based)
        matrix[row][col] = value;
    }
    
    // Reset cell value to 0
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        matrix[row][col] = 0;
    }

    // Parse an integer number starting at formula[idx]
    int getNum(int &idx, string &formula){
        int num = 0, n = formula.size();
        while(idx < n && isdigit(formula[idx])){
            num = num * 10 + (formula[idx] - '0');
            idx++;
        }
        return num;
    }

    // Get value from either a cell reference or a number
    int getFormulaValue(int &i, string &formula){
        if(formula[i] >= 'A' && formula[i] <= 'Z'){ // cell reference
            int col = formula[i++] - 'A';
            int row = getNum(i, formula) - 1;
            return matrix[row][col];
        }
        else{ // direct number
            return getNum(i, formula);
        }
    }
    
    // Evaluate a formula like "=A1+5+B2"
    int getValue(string formula) {
        int ans = 0;
        int n = formula.size();
        int i = 0;

        while(i < n){
            if(formula[i] == '='){ // skip '='
                i++;
                ans += getFormulaValue(i, formula);
            }
            else if(formula[i] == '+'){ // skip '+'
                i++;
                ans += getFormulaValue(i, formula);
            }
            else {
                i++;
            }
        }

        return ans;
    }
};

/**
 * Usage:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell("A1", 5);
 * obj->resetCell("A1");
 * int val = obj->getValue("=A1+5+B2");
 */
