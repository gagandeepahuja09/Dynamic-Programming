class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size(), ret = 1;
        map<int, int> present;
        present[A[n - 1]] = n - 1;
        vector<int> lower(n, 0), higher(n, 0);
        higher[n - 1] = lower[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            auto high = present.lower_bound(A[i]), low = present.upper_bound(A[i]);
            if(low != present.begin())
                lower[i] = higher[(--low) -> second];
            if(high != present.end())
                higher[i] =  lower[high -> second];
            if(higher[i])
                ret++;
            present[A[i]] = i;
        }
        return ret;
    }
};
