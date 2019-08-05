/*
Remove trees

Given N trees in a line with ith tree having height h[i].

You have to remove all the trees except the first one and the last one.

The cost of removing ith tree is height[i - 1] * height[i] * height[i + 1].

As soon as the tree is removed it will not exist in the line anymore.

You have to remove the trees in such a way that minimizes the cost.

Constraints:

2 <= N <= 19
0 <= h[i] <= 400

Input:

An array of length N denoting height of trees.

Output:

Integer denoting minimum cost.

Example:

Input:
[1 2 4 3]

Output:
20

Explanation:
Remove tree having height 2 first and then 4. So, total cost is (1 * 2 * 4) + (1 * 4 * 3) = 8 + 12 = 20.

×
-->
*/

int dp[20][20];

int minCost(vector<int>& A, int l, int r) {
    if(r - l <= 1) {
        return 0;
    }
    if(dp[l][r] != -1)
        return dp[l][r];
    int ans = INT_MAX;
    for(int k = l + 1; k < r; k++) {
        ans = min(ans, A[l] * A[k] * A[r] + minCost(A, l, k) + minCost(A, k, r));
    }
    return dp[l][r] = ans;
}

int Solution::solve(vector<int> &A) {
    memset(dp, -1, sizeof dp);
    return minCost(A, 0, A.size() - 1);
}

