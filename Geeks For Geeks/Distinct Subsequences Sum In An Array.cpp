// Find all distinct subset (or subsequence) sums of an array
// Can be done using DP if Sum * n --> <= 10^7
#include <bits/stdc++.h>
using namespace std;

void printDistSubsetSum(vector<int>& arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    bool dp[n + 1][sum + 1];
    // Base case: There is always a subset with sum 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
        // Always true if we have only this element
        dp[i][arr[i - 1]] = true;
        for (int j = 1; j <= sum; j++) {
            // If j sum was achievable till index i - 1, then
            // both j & (j + arr[i]) are achievable till index i
            if (dp[i - 1][j]) {
                dp[i][j] = d[i][j + arr[i - 1]] = true;
            }
        }
    }

    for (int j = 0; j <= sum; j++) {
        if (dp[n][j])
            cout << j << " "; 
    }
    cout << endl;
}
