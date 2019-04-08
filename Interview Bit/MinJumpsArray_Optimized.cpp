 int Solution::jump(vector<int> &A) {
    int n = A.size();
    if(n <= 1)
        return 0;
    if(A[0] == 0)
        return -1;
    int maxReach = A[0];
    int steps = A[0];
    int jumps = 1;
    int i = 1;
    for(i = 1; i < n; i++) {
        if(i == n - 1)
            return jumps;
        maxReach = max(maxReach, i + A[i]);
        steps--;
        // We cannot take any further steps
        if(steps == 0) {
            // We have taken a jump
            jumps++;
            if(i >= maxReach) 
                return -1;
            steps = maxReach - i;    
        }
    }
    return -1;
}

