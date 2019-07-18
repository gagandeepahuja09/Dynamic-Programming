class Solution {
public:
    vector<int> productExceptSelf(vector<int>& A) {
        int prod = 1;
        vector<int> ret(A.size(), 1);
        for(int i = 0; i < A.size(); i++) {
            ret[i] *= prod;
            prod *= A[i];
        }
        prod = 1;
        for(int i = A.size() - 1; i >= 0; i--) {
            ret[i] *= prod;
            prod *= A[i];
        }
        return ret;
    }
};
