class Solution {
public:
    unordered_map<int, unordered_map<int, int>> mp;
    int target;
    int f(vector<int>& A, int sum, int i) {
        if(i == A.size())
            return sum == target;
        if(mp.count(sum) && mp[sum].count(i)) {
            return mp[sum][i];
        }
        int op1 = f(A, sum - A[i], i + 1);
        int op2 = f(A, sum + A[i], i + 1);
        return mp[sum][i] = op1 + op2;
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        target = S;
        return f(nums, 0, 0);
    }
};
