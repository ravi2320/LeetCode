/*
2115. Find All Possible Recipes from Given Supplies
Solved
Medium
Topics
Companies
Hint
You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

 

Example 1:

Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
Example 2:

Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
Example 3:

Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".
 

Constraints:

n == recipes.length == ingredients.length
1 <= n <= 100
1 <= ingredients[i].length, supplies.length <= 100
1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
All the values of recipes and supplies combined are unique.
Each ingredients[i] does not contain any duplicate values.
*/

// --------------------------------------------
// 🚀 Approach, Intuition, Time & Space Complexity:
// 
// Approach & Intuition:
// - We treat each recipe as something we can "cook" only if all its ingredients are available.
// - Use an unordered_set to track all currently available supplies.
// - Iterate over the recipes multiple times:
//     - For each recipe, check if all its ingredients are available in the supplies set.
//     - If yes, mark it as cooked, add it to supplies, and append it to the result.
// - Repeat until no more recipes can be cooked.
//
// Time Complexity: O(n^2 * m)
// - Outer loop runs at most n times (number of recipes).
// - Inner loop iterates n recipes, each having up to m ingredients.
// 
// Space Complexity: O(n + s)
// - Unordered_set stores up to n + s strings (n = recipes, s = initial supplies).
// - Boolean vector of size n.
// - Result vector of size up to n.
// --------------------------------------------

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();

        // Store initial supplies in a set for O(1) lookups
        unordered_set<string> available(supplies.begin(), supplies.end());

        // Boolean vector to track which recipes are already cooked
        vector<bool> isCooked(n, false);

        // Result vector to store successfully cooked recipes
        vector<string> result;

        // Counter to control loop
        int remaining = n;

        // Loop runs until no more recipes can be cooked
        while (remaining--) {
            for (int i = 0; i < n; i++) {
                if (isCooked[i]) continue; // Skip already cooked recipes

                bool canCook = true;

                // Check if all ingredients of current recipe are available
                for (const string& ing : ingredients[i]) {
                    if (!available.count(ing)) {
                        canCook = false;
                        break;
                    }
                }

                // If all ingredients are available, mark recipe as cooked
                if (canCook) {
                    isCooked[i] = true;
                    available.insert(recipes[i]); // Add cooked recipe to supplies
                    result.push_back(recipes[i]); // Add to result
                }
            }
        }

        return result;
    }
};


// ---------------------------------------------------------
// 🚀 Approach, Intuition, Time & Space Complexity:
//
// Approach & Intuition:
// - Model the problem as a **Graph** where:
//     - Each recipe depends on ingredients (edges).
// - Use **Kahn’s Algorithm (Topological Sort)** to process recipes.
// - Track in-degree of each recipe (number of missing ingredients).
// - Ingredients from `supplies` are considered available initially.
//
// Steps:
// 1. Create a mapping of ingredients → recipes that need them.
// 2. For each recipe, increase its in-degree if ingredient not in supplies.
// 3. Push recipes with in-degree 0 to queue (can be made immediately).
// 4. Process queue, reduce in-degree of dependent recipes.
// 5. Add recipe to result if it becomes cookable.
//
// Time Complexity: O(N * M)
// - N = number of recipes
// - M = average number of ingredients per recipe
//
// Space Complexity: O(N * M)
// - For adjacency list, in-degree array, queue, and result
// ---------------------------------------------------------

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        
        // Step 1: Add supplies to a set for quick lookup
        unordered_set<string> available(supplies.begin(), supplies.end());
        
        // Step 2: Build graph - ingredient to dependent recipes
        unordered_map<string, vector<int>> adj;
        vector<int> indegree(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (string &ingredient : ingredients[i]) {
                if (!available.count(ingredient)) {
                    adj[ingredient].push_back(i); // ingredient → recipe index
                    indegree[i]++; // Increase in-degree of recipe
                }
            }
        }
        
        // Step 3: Initialize queue with recipes having zero in-degree
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Step 4: Process the queue
        vector<string> result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(recipes[u]); // Recipe can be cooked
            available.insert(recipes[u]); // Add to available supplies
            
            // Step 5: Update dependent recipes
            for (int &v : adj[recipes[u]]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return result;
    }
};
