/*
1912. Design Movie Rental System

avatar
Discuss Approach
arrow-up
Solved
Hard
Topics
premium lock icon
Companies
Hint
You have a movie renting company consisting of n shops. You want to implement a renting system that supports searching for, booking, and returning movies. The system should also support generating a report of the currently rented movies.

Each movie is given as a 2D integer array entries where entries[i] = [shopi, moviei, pricei] indicates that there is a copy of movie moviei at shop shopi with a rental price of pricei. Each shop carries at most one copy of a movie moviei.

The system should support the following functions:

Search: Finds the cheapest 5 shops that have an unrented copy of a given movie. The shops should be sorted by price in ascending order, and in case of a tie, the one with the smaller shopi should appear first. If there are less than 5 matching shops, then all of them should be returned. If no shop has an unrented copy, then an empty list should be returned.
Rent: Rents an unrented copy of a given movie from a given shop.
Drop: Drops off a previously rented copy of a given movie at a given shop.
Report: Returns the cheapest 5 rented movies (possibly of the same movie ID) as a 2D list res where res[j] = [shopj, moviej] describes that the jth cheapest rented movie moviej was rented from the shop shopj. The movies in res should be sorted by price in ascending order, and in case of a tie, the one with the smaller shopj should appear first, and if there is still tie, the one with the smaller moviej should appear first. If there are fewer than 5 rented movies, then all of them should be returned. If no movies are currently being rented, then an empty list should be returned.
Implement the MovieRentingSystem class:

MovieRentingSystem(int n, int[][] entries) Initializes the MovieRentingSystem object with n shops and the movies in entries.
List<Integer> search(int movie) Returns a list of shops that have an unrented copy of the given movie as described above.
void rent(int shop, int movie) Rents the given movie from the given shop.
void drop(int shop, int movie) Drops off a previously rented movie at the given shop.
List<List<Integer>> report() Returns a list of cheapest rented movies as described above.
Note: The test cases will be generated such that rent will only be called if the shop has an unrented copy of the movie, and drop will only be called if the shop had previously rented out the movie.

 

Example 1:

Input
["MovieRentingSystem", "search", "rent", "rent", "report", "drop", "search"]
[[3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]], [1], [0, 1], [1, 2], [], [1, 2], [2]]
Output
[null, [1, 0, 2], null, null, [[0, 1], [1, 2]], null, [0, 1]]

Explanation
MovieRentingSystem movieRentingSystem = new MovieRentingSystem(3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]);
movieRentingSystem.search(1);  // return [1, 0, 2], Movies of ID 1 are unrented at shops 1, 0, and 2. Shop 1 is cheapest; shop 0 and 2 are the same price, so order by shop number.
movieRentingSystem.rent(0, 1); // Rent movie 1 from shop 0. Unrented movies at shop 0 are now [2,3].
movieRentingSystem.rent(1, 2); // Rent movie 2 from shop 1. Unrented movies at shop 1 are now [1].
movieRentingSystem.report();   // return [[0, 1], [1, 2]]. Movie 1 from shop 0 is cheapest, followed by movie 2 from shop 1.
movieRentingSystem.drop(1, 2); // Drop off movie 2 at shop 1. Unrented movies at shop 1 are now [1,2].
movieRentingSystem.search(2);  // return [0, 1]. Movies of ID 2 are unrented at shops 0 and 1. Shop 0 is cheapest, followed by shop 1.
 

Constraints:

1 <= n <= 3 * 105
1 <= entries.length <= 105
0 <= shopi < n
1 <= moviei, pricei <= 104
Each shop carries at most one copy of a movie moviei.
At most 105 calls in total will be made to search, rent, drop and report.
*/

/*
Approach:
1. Data Structures:
   - available[movie]: set of {price, shop}, keeps track of available copies of a movie sorted by (price, shop).
   - movieToShopPrice[movie]: set of {shop, price}, allows quick lookup of price given a (shop, movie).
   - rented: set of {price, shop, movie}, keeps track of rented movies sorted by (price, shop, movie).
   
2. search(movie):
   - Look at `available[movie]` (sorted by price, then shop).
   - Return up to 5 shop IDs where the movie is available.

3. rent(shop, movie):
   - Find the price of (shop, movie) using `movieToShopPrice`.
   - Remove (price, shop) from available[movie].
   - Insert (price, shop, movie) into rented.

4. drop(shop, movie):
   - Find price of (shop, movie).
   - Add it back to available[movie].
   - Remove from rented.

5. report():
   - Iterate through `rented` (sorted by price, then shop, then movie).
   - Return up to 5 {shop, movie} pairs.

Intuition:
- This problem mimics an online movie renting system.
- We need quick queries for:
  a) Finding cheapest shops for a movie.  
  b) Tracking currently rented movies in sorted order.  
- Balanced BST (`set`) helps maintain sorted order while supporting log(N) insert/erase.  
- Maps are used for quick lookup of movie-to-shop-price mappings.

Time Complexity:
- search(movie): O(5) = O(1) (just iterating over first 5 elements).
- rent/drop: O(log N) (set insert/erase).
- report: O(5) = O(1) (first 5 elements).
- Overall: O(log N) per update/query.

Space Complexity:
- O(N) for storing entries in sets and maps (N = number of entries).

*/

class MovieRentingSystem {
    typedef pair<int, int> P;  
    // movie -> set of (price, shop), sorted by price then shop
    unordered_map<int, set<P>> available;
    // movie -> set of (shop, price), sorted by shop (for lookup)
    unordered_map<int, set<P>> movieToShopPrice;
    // rented movies: {price, shop, movie}, sorted lexicographically
    set<tuple<int, int, int>> rented;

public:
    // Initialize system with given entries [shop, movie, price]
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &entry : entries){
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            available[movie].insert({price, shop});
            movieToShopPrice[movie].insert({shop, price});
        }
    }
    
    // Search top 5 cheapest shops for given movie
    vector<int> search(int movie) {
        vector<int> res;
        int cnt = 0;

        if(available.count(movie)){
            for(auto &[price, shop] : available[movie]){
                res.push_back(shop);
                cnt++;
                if(cnt >= 5) break;
            }
        }
        return res;
    }
    
    // Rent a movie from a given shop
    void rent(int shop, int movie) {
        auto it = movieToShopPrice[movie].lower_bound({shop, INT_MIN});
        int price = it->second;

        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    // Drop a movie back to shop (make it available again)
    void drop(int shop, int movie) {
        auto it = movieToShopPrice[movie].lower_bound({shop, INT_MIN});
        int price = it->second;

        available[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }
    
    // Report top 5 rented movies sorted by price, then shop, then movie
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;

        for(auto &[price, shop, movie] : rented){
            res.push_back({shop, movie});
            cnt++;
            if(cnt >= 5) break;
        }
        return res;
    }
};

/**
 * Usage Example:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> shops = obj->search(movie);
 * obj->rent(shop, movie);
 * obj->drop(shop, movie);
 * vector<vector<int>> rentedMovies = obj->report();
 */
