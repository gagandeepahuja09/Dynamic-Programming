vector<int> Solution::solve(int A, int B, int C, int D) {
    int ia, ib, ic, nexta = A, nextb = B, nextc = C;
    ia = ib = ic = 0;
    vector<int> ret;
    for(int i = 0; i < D; i++) {
        ret.push_back(min(nexta, min(nextb, nextc)));
        if(ret[i] == nexta)
            nexta = ret[ia++] * A;
        if(ret[i] == nextb)
            nextb = ret[ib++] * B;
        if(ret[i] == nextc)
            nextc = ret[ic++] * C;
    }
    return ret;
}

