int Solution::jump(vector<int> &A) {
    if(A.size() <= 1)
        return 0;
    int level = 0;
    int currMax = 0, i = 0;
    while(i <= currMax) {
        int farthest = currMax;
        for(; i <= currMax; i++) {
            farthest = max(farthest, i + A[i]);
            if(farthest >= A.size() - 1)
                return level + 1;
        }
        currMax = farthest;
        level++;
    }
    return -1;
}

