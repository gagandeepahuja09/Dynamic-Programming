bool cmp(vector<int> A, vector<int> B) {
    if(A.size() == B.size())
        return A < B;
    return A.size() < B.size();    
}

int partitionSet(vector<int> &A, int start, int end, int s1, int sum, vector<int>& v, vector<int>& v1) {
    if(start == end) {
        if(v.size()) {
            if((s1 * (A.size() - v.size())) == ((sum - s1) * (v.size()))) {
                v1 = v;
                return 1;
            }
        }
        return 0;    
    }
    int option1 = partitionSet(A, start + 1, end, s1, sum, v, v1);
    v.push_back(A[start]);
    int option2 = partitionSet(A, start + 1, end, s1 + A[start], sum, v, v1);
    v.pop_back();
    return option1 || option2;
}

vector<vector<int> > Solution::avgset(vector<int> &A) {
    int n =  A.size();
    int sum = 0;
    for(int i=0; i<A.size(); i++)
        sum += A[i];
    vector<int> v;
    vector<int> v1;
    vector<vector<int>> res;
    if(partitionSet(A, 0, n-1, 0, sum, v, v1)) {
        sort(v1.begin(), v1.end());
        res.push_back(v1);
        vector<int> v2;
        for(int i=0; i<A.size(); i++)
            if(find(v1.begin(), v1.end(), A[i]) == v1.end())
                v2.push_back(A[i]);
        sort(v2.begin(), v2.end());        
        res.push_back(v2);    
    }
    sort(res.begin(), res.end(), cmp);
    return res;
}

