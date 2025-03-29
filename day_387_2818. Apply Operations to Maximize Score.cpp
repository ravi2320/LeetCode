/*
2818. Apply Operations to Maximize Score
Solved
Hard
Topics
Companies
Hint
You are given an array nums of n positive integers and an integer k.

Initially, you start with a score of 1. You have to maximize your score by applying the following operation at most k times:

Choose any non-empty subarray nums[l, ..., r] that you haven't chosen previously.
Choose an element x of nums[l, ..., r] with the highest prime score. If multiple such elements exist, choose the one with the smallest index.
Multiply your score by x.
Here, nums[l, ..., r] denotes the subarray of nums starting at index l and ending at the index r, both ends being inclusive.

The prime score of an integer x is equal to the number of distinct prime factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5.

Return the maximum possible score after applying at most k operations.

Since the answer may be large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [8,3,9,3,8], k = 2
Output: 81
Explanation: To get a score of 81, we can apply the following operations:
- Choose subarray nums[2, ..., 2]. nums[2] is the only element in this subarray. Hence, we multiply the score by nums[2]. The score becomes 1 * 9 = 9.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 1, but nums[2] has the smaller index. Hence, we multiply the score by nums[2]. The score becomes 9 * 9 = 81.
It can be proven that 81 is the highest score one can obtain.
Example 2:

Input: nums = [19,12,14,6,10,18], k = 3
Output: 4788
Explanation: To get a score of 4788, we can apply the following operations: 
- Choose subarray nums[0, ..., 0]. nums[0] is the only element in this subarray. Hence, we multiply the score by nums[0]. The score becomes 1 * 19 = 19.
- Choose subarray nums[5, ..., 5]. nums[5] is the only element in this subarray. Hence, we multiply the score by nums[5]. The score becomes 19 * 18 = 342.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 2, but nums[2] has the smaller index. Hence, we multipy the score by nums[2]. The score becomes 342 * 14 = 4788.
It can be proven that 4788 is the highest score one can obtain.
 

Constraints:

1 <= nums.length == n <= 105
1 <= nums[i] <= 105
1 <= k <= min(n * (n + 1) / 2, 109)
*/

/*
Approach:
1. **Calculate Prime Scores for Each Number**:
   - Count the number of distinct prime factors for each element in `nums`.
   - Use the **Sieve of Eratosthenes** to get prime numbers up to `max(nums)`, then count prime factors efficiently.

2. **Find Previous and Next Greater Prime Scores**:
   - Use **monotonic stacks** to compute the **next greater** and **previous greater** indices for prime scores.

3. **Compute Subarray Contributions**:
   - Each element contributes to `(nextGreater[i] - i) * (i - prevGreater[i])` subarrays.

4. **Sort Numbers in Descending Order & Compute Score Greedily**:
   - Start from the **largest element** and multiply its power greedily until `k` operations are exhausted.
   - Use **modular exponentiation** for power calculations.

Intuition:
- Sorting numbers in descending order ensures we maximize the product early.
- Using **monotonic stacks** optimizes finding the nearest greater elements in **O(N)** time.
- **Modular exponentiation** efficiently handles large exponents under modulo constraints.

Time Complexity:
- **O(M log log M) + O(N log M)** → Prime factorization (where M is max(nums)).
- **O(N)** → Finding next/previous greater elements using monotonic stacks.
- **O(N log N)** → Sorting numbers by value.
- **O(K log Operations)** → Greedy selection with modular exponentiation.
- **Overall Complexity:** **O(N log N + M log log M)** (since M ≤ max(nums), which is manageable).

Space Complexity:
- **O(N)** → Prime score storage.
- **O(N)** → Next and previous greater element indices.
- **O(N)** → Sorted pairs of `(num, index)`.
- **Overall:** **O(N)**.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Efficient Modular Exponentiation (Binary Exponentiation)
    long long findPower(long long a, long long b) {
        if (b == 0) return 1;
        long long half = findPower(a, b / 2);
        long long result = (half * half) % MOD;
        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }
        return result;
    }

    // Generate primes up to 'limit' using Sieve of Eratosthenes
    vector<int> getPrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }

    // Compute Prime Scores (Distinct Prime Factors Count)
    vector<int> findPrimeScores(vector<int>& nums) {
        int n = nums.size();
        vector<int> primeScores(n, 0);

        int maxElement = *max_element(begin(nums), end(nums));
        vector<int> primes = getPrimes(maxElement); // O(M log log M)

        for (int i = 0; i < n; i++) { // O(N log M)
            int num = nums[i];

            for (int prime : primes) {
                if (prime * prime > num) break; // No need to check further
                
                if (num % prime == 0) { 
                    primeScores[i]++;
                    while (num % prime == 0) {
                        num /= prime;
                    }
                }
            }
            if (num > 1) { // A remaining prime factor > sqrt(num)
                primeScores[i]++;
            }
        }

        return primeScores;
    }

    // Find Next Greater Prime Score using Monotonic Stack
    vector<int> findNextGreater(vector<int>& primeScores) {
        int n = primeScores.size();
        vector<int> nextGreater(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && primeScores[st.top()] <= primeScores[i]) {
                st.pop();
            }

            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nextGreater;
    }

    // Find Previous Greater Prime Score using Monotonic Stack
    vector<int> findPrevGreater(vector<int>& primeScores) {
        int n = primeScores.size();
        vector<int> prevGreater(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && primeScores[st.top()] < primeScores[i]) {
                st.pop();
            }

            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return prevGreater;
    }

    // Compute Maximum Score
    int maximumScore(vector<int>& nums, int k) {
        vector<int> primeScores = findPrimeScores(nums); // O(M log log M + N log M)
        vector<int> nextGreater = findNextGreater(primeScores); // O(N)
        vector<int> prevGreater = findPrevGreater(primeScores); // O(N)

        int n = nums.size();
        vector<long long> subarrays(n, 0);

        for (int i = 0; i < n; i++) { // O(N)
            subarrays[i] = (long long)(nextGreater[i] - i) * (i - prevGreater[i]);
        }

        // Store numbers along with their indices
        vector<pair<int, int>> sortedNums(n);
        for (int i = 0; i < n; i++) {
            sortedNums[i] = {nums[i], i};
        }

        // Sort numbers in descending order to process larger values first
        sort(begin(sortedNums), end(sortedNums), greater<>()); // O(N log N)

        long long score = 1;
        int idx = 0;

        // Process elements greedily until 'k' operations are used
        while (k > 0) { // O(K log Operations)
            auto [num, i] = sortedNums[idx];

            long long operations = min((long long)k, subarrays[i]);

            score = (score * findPower(num, operations)) % MOD;

            k -= operations;
            idx++;
        }

        return score;
    }
};

// Driver Code
int main() {
    vector<int> nums = {8, 12, 18, 15, 25};
    int k = 3;

    Solution obj;
    int result = obj.maximumScore(nums, k);

    cout << "Maximum Score: " << result << endl;

    return 0;
}