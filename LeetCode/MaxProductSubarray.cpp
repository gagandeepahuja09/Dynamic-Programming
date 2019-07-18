class Solution {
public:
    int maxProduct(vector<int>& A) {
        int imin, imax, ret;
        ret = imin = imax = A[0];
        for(int i = 1; i < A.size(); i++) {
            if(A[i] < 0) {
                swap(imax, imin);
            }
            imax = max(A[i], imax * A[i]);
            imin = min(A[i], imin * A[i]);
                
            ret = max(ret, imax);    
        }
        return ret;
    }
};
