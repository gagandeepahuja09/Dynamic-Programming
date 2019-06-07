vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> res;
    int n = B.size();
    int m = B[0].size();
    for(int i=0; i<n; i++)
    {
        res.push_back(B[i]);
    }
    for(int k=1; k<=A; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i>0)
                    res[i][j] = max(res[i][j], B[i-1][j]);
                if(i<n-1)
                    res[i][j] = max(res[i][j],B[i+1][j]);
                if(j>0)
                    res[i][j] = max(res[i][j], B[i][j-1]);
                if(j<m-1)
                    res[i][j] = max(res[i][j],B[i][j+1]);    
            }
        }
        B = res;
    }
    return res;
}

