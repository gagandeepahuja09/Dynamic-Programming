/*
Maximum Sum

You are given an array A of N integers and three integers X, Y, and Z.

You have to find the maximum value of A[i]*X + A[j]*Y + A[k]*Z, where 1 <= i <= j <= k <= N.
*/

int dp[100001][2][2][2];

int maxSum(vector<int> &A, int x, int y, int z, int tx, int ty, int tz, int i) {
    if(i == A.size() && tx && ty && tz)
        return 0;
    if(i == A.size())
        return INT_MIN;
    if(dp[i][tx][ty][tz] != -1)
        return dp[i][tx][ty][tz];
    int option1 = INT_MIN, option2 = INT_MIN, option3 = INT_MIN, option4;
    if(!tx && !ty && !tz) 
        option1 = A[i] * x + maxSum(A, x, y, z, 1, ty, tz, i);
    else if(tx && !ty && !tz)    
        option2 = A[i] * y + maxSum(A, x, y, z, tx, 1, tz, i);
    else if(tx && ty && !tz)    
        option3 = A[i] * z + maxSum(A, x, y, z, tx, ty, 1, i);
    option4 = maxSum(A, x, y, z, tx, ty, tz, i + 1);
    return dp[i][tx][ty][tz] = max(max(option1, option2), max(option3, option4));
}

int Solution::solve(vector<int> &A, int B, int C, int D) {
    memset(dp, -1, sizeof dp);
    return maxSum(A, B, C, D, 0, 0, 0, 0);
}

