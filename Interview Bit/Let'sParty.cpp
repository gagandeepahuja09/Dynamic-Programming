/*
Let's Party

In Danceland, one person can party either alone or can pair up with another person.

Can you find in how many ways they can party if there are N people in Danceland?

Input Format

Given only argument A of type Integer, number of people in Danceland.

Output Format

Return a single integer N mod 10003, i.e number of ways people of Danceland can party.

Constraints

1 <= N <= 1e5 

Example

Input:
    N = 3

Output :
    4

Explanation :
    Let suppose three people are A, B, and C.
    There are only 4 ways to party as,
    (A, B, C) All party alone
    (AB, C) A and B party together and C party alone
    (AC, B) A and C party together and B party alone
    (BC, A) B and C party together and A party alone
    here 4 % 10003 = 4, so answer is 4.

*/

#define MOD 10003
#define ll long long int

ll party(int n, vector<ll>& dp) {
    if(n == 0|| n == 1)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    return dp[n] = (party(n - 1, dp) % MOD + ((n - 1) % MOD * party(n - 2, dp) % MOD) % MOD) % MOD;    
}

int Solution::solve(int A) {
    vector<ll> dp(A + 1, -1);
    dp[0] = 1, dp[1] = 1;
    for(int i = 2; i <= A; i++) {
        dp[i] = (dp[i - 1] % MOD + ((i - 1) % MOD * dp[i - 2] % MOD) % MOD) % MOD;
    }
    return (int)(dp[A]);
}

