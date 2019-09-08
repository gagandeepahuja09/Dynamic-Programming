class Solution {
public:
    int maximumSum(vector<int>& A) {
        int n = A.size(), ret = 0;
        if(!n)
            return 0;
        ret = A[0];
        vector<int> l(n), r(n);
        l[0] = A[0];
        for(int i = 1; i < n; i++) {
            l[i] = max(A[i], l[i - 1] + A[i]);          
        }
        r[n - 1] = A[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            r[i] = max(A[i], r[i + 1] + A[i]);
        }
        for(int i = 1; i < n - 1; i++) {
            ret = max(l[i - 1] + r[i + 1], ret);
            ret = max(ret, l[i]);
        }
        if(n > 1) {
            ret = max(ret, r[1]);
            ret = max(ret, l[n - 2]);
        }
        return max(ret, l[n - 1]);
    }
};
