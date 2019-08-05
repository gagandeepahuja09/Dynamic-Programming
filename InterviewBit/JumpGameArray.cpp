int Solution::canJump(vector<int> &A) {
    int last = A.size() - 1;
    for(int i = A.size() - 2; i >= 0; i--) {
        if(i + A[i] >= last)
            last = i;
    }
    return (last <= 0);
}

