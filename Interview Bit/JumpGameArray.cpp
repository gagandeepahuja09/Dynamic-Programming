int Solution::canJump(vector<int> &A) {
    int steps = A[0], jumps = 1, maxReach = A[0];
    for(int i = 0; i < A.size(); i++) {
        if(i == A.size() - 1)
            return 1;
        maxReach = max(maxReach, i + A[i]);
        if(maxReach <= i)
            return 0;
        steps--;
        if(!steps) {
            jumps++;
            steps = (maxReach - i);
        }
    } 
    return 0;
}

