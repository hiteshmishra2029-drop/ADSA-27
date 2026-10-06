#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Function to solve TSP using DP + Bitmask
int tsp(int mask, int pos, vector<vector<int>> &dist, vector<vector<int>> &dp) {
    int n = dist.size();

    // Base case: all cities visited
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // return to starting city
    }

    // Already computed
    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;

    // Try next city
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { // if not visited
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    // Example distance matrix (symmetric TSP)
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int n = dist.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    cout << "Minimum cost of TSP tour: " << tsp(1, 0, dist, dp) << endl;

    return 0;
}
