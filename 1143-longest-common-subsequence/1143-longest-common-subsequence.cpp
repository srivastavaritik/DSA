class Solution {
public:
    int longestCommonSubsequence(string X, string Y) {
        int n=X.length(), m=Y.length();
        int LCS_table[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
        if (i == 0 || j == 0)
            LCS_table[i][j] = 0;
        else if (X[i - 1] == Y[j - 1])
            LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
        else
            LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j-1]);
            }
        }
        return LCS_table[n][m];
    }
};