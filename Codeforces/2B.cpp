#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define N 1005


int n, a[N][N], dp2[N][N], dp5[N][N]; 
 
void walk(int dp[N][N], int i, int j) {
    if(i == 1 && j == 1)
        return;
    if(dp[i - 1][j] < dp[i][j - 1]) {
        walk(dp, i - 1, j);
        printf("D");
    }
    else {
        walk(dp, i, j - 1);
        printf("R");
    }
} 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	memset(dp2, 50, sizeof dp2);
	memset(dp5, 50, sizeof dp5);
	dp2[0][1] = dp5[0][1] = dp2[1][0] = dp5[1][0] = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
	    for(int j = 1; j <= n; j++) {
	        cin >> a[i][j];
	    }
	}
	bool zero = false;
	int x, y;
	for(int i = 1; i <= n; i++) {
	    for(int j = 1; j <= n; j++) {
	        if(!a[i][j]) {
	            zero = 1;
	            x = i; y = j;
	            continue;
	        }
	        int num = a[i][j], c2 = 0, c5 = 0;
	        while(num % 2 == 0) {
	            num /= 2;
	            c2++;
	        }
	        while(num % 5 == 0) {
	            num /= 5;
	            c5++;
	        }
	        dp2[i][j] = c2 + min(dp2[i - 1][j], dp2[i][j - 1]);
	        dp5[i][j] = c5 + min(dp5[i - 1][j], dp5[i][j - 1]);
	    }
	}
	int lrnd = min(dp2[n][n], dp5[n][n]);
	if(zero)
	    lrnd = min(lrnd, 1);
	printf("%d\n", lrnd);    
	if(lrnd == dp2[n][n])
	    walk(dp2, n, n);
	else if(lrnd == dp5[n][n])
	    walk(dp5, n, n);
	else {
	    int i = 1, j = 1;
	    while(i < x)
	        printf("D"), ++i;
	    while(j < y)
	        printf("R"), ++j;
	    while(i < n)
	        printf("D"), ++i;
	    while(j < n)
	        printf("R"), ++j;     
	} 
}

