/*
2043. Simple Bank System

avatar
Discuss Approach
arrow-up
Solved
Medium
Topics
premium lock icon
Companies
Hint
You have been tasked with writing a program for a popular bank that will automate all its incoming transactions (transfer, deposit, and withdraw). The bank has n accounts numbered from 1 to n. The initial balance of each account is stored in a 0-indexed integer array balance, with the (i + 1)th account having an initial balance of balance[i].

Execute all the valid transactions. A transaction is valid if:

The given account number(s) are between 1 and n, and
The amount of money withdrawn or transferred from is less than or equal to the balance of the account.
Implement the Bank class:

Bank(long[] balance) Initializes the object with the 0-indexed integer array balance.
boolean transfer(int account1, int account2, long money) Transfers money dollars from the account numbered account1 to the account numbered account2. Return true if the transaction was successful, false otherwise.
boolean deposit(int account, long money) Deposit money dollars into the account numbered account. Return true if the transaction was successful, false otherwise.
boolean withdraw(int account, long money) Withdraw money dollars from the account numbered account. Return true if the transaction was successful, false otherwise.
 

Example 1:

Input
["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
[[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]
Output
[null, true, true, true, false, false]

Explanation
Bank bank = new Bank([10, 100, 20, 50, 30]);
bank.withdraw(3, 10);    // return true, account 3 has a balance of $20, so it is valid to withdraw $10.
                         // Account 3 has $20 - $10 = $10.
bank.transfer(5, 1, 20); // return true, account 5 has a balance of $30, so it is valid to transfer $20.
                         // Account 5 has $30 - $20 = $10, and account 1 has $10 + $20 = $30.
bank.deposit(5, 20);     // return true, it is valid to deposit $20 to account 5.
                         // Account 5 has $10 + $20 = $30.
bank.transfer(3, 4, 15); // return false, the current balance of account 3 is $10,
                         // so it is invalid to transfer $15 from it.
bank.withdraw(10, 50);   // return false, it is invalid because account 10 does not exist.
 

Constraints:

n == balance.length
1 <= n, account, account1, account2 <= 105
0 <= balance[i], money <= 1012
At most 104 calls will be made to each function transfer, deposit, withdraw.
*/

/**
 * Intuition:
 * The Bank class simulates a simple banking system with operations for transferring money between accounts,
 * depositing money to an account, and withdrawing money from an account. The key data structure used here is a 
 * vector of long long integers (`balance`), which keeps track of the balance for each account. 
 * 
 * - The constructor initializes the bank with an initial balance for each account.
 * - `transfer` method transfers money between two accounts after checking valid conditions.
 * - `deposit` adds money to a specific account.
 * - `withdraw` removes money from an account, provided that the balance is sufficient.
 *
 * Time Complexity:
 * - Constructor: O(n), where n is the number of accounts. It initializes the `balance` vector with the account balances.
 * - `transfer`: O(1), since we are simply accessing and updating two elements in the `balance` vector.
 * - `deposit`: O(1), since we just access and update a single element in the `balance` vector.
 * - `withdraw`: O(1), since we are accessing and updating a single element in the `balance` vector.
 * 
 * Space Complexity:
 * - O(n), where n is the number of accounts. We store the balance for each account in the vector `balance`.
 */

class Bank {
    vector<long long> balance; // Vector to store balance of each account
    int n; // Number of accounts in the bank

public:
    // Constructor to initialize the bank with account balances
    Bank(vector<long long>& balance) {
        this->balance = balance; // Initialize balance vector with the provided values
        n = balance.size(); // Set n to the size of balance vector
    }

    // Method to transfer money between two accounts
    bool transfer(int account1, int account2, long long money) {
        // Check if accounts are valid (1 <= account1, account2 <= n) and if account1 has enough balance
        if(account1 < 1 || account2 < 1 || account1 > n || account2 > n || balance[account1-1] < money)
            return false; // If any condition fails, return false

        // Deduct money from account1 and add it to account2
        balance[account1-1] -= money;
        balance[account2-1] += money;

        return true; // Transfer successful
    }

    // Method to deposit money into a specific account
    bool deposit(int account, long long money) {
        // Check if the account number is valid (1 <= account <= n)
        if(account < 1 || account > n)
            return false; // If invalid, return false

        // Add the money to the specified account
        balance[account-1] += money;

        return true; // Deposit successful
    }

    // Method to withdraw money from a specific account
    bool withdraw(int account, long long money) {
        // Check if the account is valid (1 <= account <= n) and if the account has enough balance
        if(account < 1 || account > n || balance[account-1] < money)
            return false; // If any condition fails, return false

        // Deduct money from the account
        balance[account-1] -= money;
        
        return true; // Withdrawal successful
    }
};

/**
 * Example usage:
 * 
 * Bank* obj = new Bank(balance);  // Create a bank object with initial balances
 * bool param_1 = obj->transfer(account1, account2, money); // Transfer money between accounts
 * bool param_2 = obj->deposit(account, money); // Deposit money to an account
 * bool param_3 = obj->withdraw(account, money); // Withdraw money from an account
 */
