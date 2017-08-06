// naive splution 
int longestCommonSubstring(string &A, string &B) {
    int m = A.size();
    int n = B.size();
    if (m == 0 || n == 0) return 0;
    int maxlen = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (A[i] == B[j]) {
                int curlen = 0;
                int k = i, l = j;
                while (k < m && l < n && A[k++] == B[l++])
                    curlen++;
                if (curlen > maxlen)
                    maxlen = curlen;
            }
        }
    }

    return maxlen;
}


//dynammic programming
int longestCommonSubstring(string &A, string &B) {
    int m = A.size();
    int n = B.size();
    if (m == 0 || n == 0) return 0;

    vector<vector<int> > dp(m, vector<int>(n, 0));
    for (int i=0; i<m; i++)
        dp[i][0] = (A[i] == B[0])?1:0;
    for (int j=0; j<n; j++)
        dp[0][j] = (A[0] == B[j])?1:0;

    int maxlen = 0;
    for (int i=1; i<m; i++) {
        for (int j=1; j<n; j++) {
            if (i > 0 && j > 0)
                dp[i][j] = (A[i] == B[i])?dp[i-1][j-1]+1:0;
            if (dp[i][j] > maxlen)
                maxlen = dp[i][j];
        }
    }

    return maxlen;

}