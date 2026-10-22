#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n = 3; // 3 Cities: 0, 1, 2

// Cost Matrix
int cost[3][3] = {
    {0, 10, 20},
    {10, 0, 15},
    {20, 15, 0}
};

int dp[1 << 3][3]; // Memoization table (8 x 3)

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) return cost[pos][0]; // Return to start (City 0)
    if (dp[mask][pos] != -1) return dp[mask][pos];

    int minCost = INF;
    for (int next = 0; next < n; next++) {
        if ((mask & (1 << next)) == 0) { // If city 'next' is unvisited
            int newCost = cost[pos][next] + tsp(mask | (1 << next), next);
            minCost = min(minCost, newCost);
        }
    }
    return dp[mask][pos] = minCost;
}

int main() {
    // Correctly initialize the entire 2D DP array with -1
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), -1);
    
    // Start at City 0 (mask = 1 because bit 0 is set)
    cout << "Minimum Cost: " << tsp(1, 0) << endl; 
    return 0;
}
