/*Remove the Substring

Given 2 strings of lowercase alphabets A and B of size N and M respectively.

it is guaranteed that B is a subsequence of A.

For example, the strings "test", "tst", "tt", "et" and "" are subsequences of the string "test". But the strings "tset", "se", "contest" are not subsequences of the string "test".

You need to remove some substring(contiguous subsequence) from A of maximum possible length such that after removing this substring B will remain a subsequence of A.

If you want to remove the substring A[l::r] then the string A will be transformed to A1A2…Al−1Ar+1Ar+2…A|A|−1A|A| (where |A| is the length of A).

Find and return the maximum possible length of the substring you can remove so that B is still a subsequence of A.*/

int Solution::solve(string s, string t) {
    int n = t.size(), m = s.size();
    vector<int> l(n, -1), r(n, s.size());
    int i = 0;
    for(int j = 0; j < s.size(); j++) {
        if(t[i] == s[j]) {
            l[i] = j;
            i++;
        }
    }
    i = n - 1;
    for(int j = s.size() - 1; j >= 0; j--) {
        if(t[i] == s[j]) {
            r[i] = j;
            i--;
        }
    }
    int ans = r[0];
    for(int i = 0; i < n - 1; i++) {
        // cout << l[i] << " " << r[i + 1] << " ";
        ans = max(ans, r[i + 1] - l[i] - 1);
    }
    ans = max(ans, m - l[n - 1] - 1);
    return ans;
}

