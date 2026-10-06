#include <bits/stdc++.h>
using namespace std;

// Function to find length of LCS
int LCS(string X, string Y) {
    int m = X.size();
    int n = Y.size();

    // DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build table bottom-up
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];  // match → extend subsequence
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // skip one character
            }
        }
    }

    return dp[m][n];  // length of LCS
}

// Function to reconstruct the LCS string
string getLCS(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to get the actual LCS string
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs.push_back(X[i - 1]);
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    cout << "Length of LCS: " << LCS(X, Y) << endl;
    cout << "LCS string: " << getLCS(X, Y) << endl;

    return 0;
}
