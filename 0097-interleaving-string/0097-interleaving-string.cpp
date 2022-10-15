class Solution {
public:
    int f(int i, int j, string &a, string &b, string &c, vector<vector<int>> &dp, int aN, int bN, int cN) {
        if (i > aN || j > bN) return false;
        if (dp[i][j] != -1) return dp[i][j];
        if (
            (i + j == cN - 1) 
            && (
                    (i < aN && a[i] == c[i + j]) 
                    || 
                    (j < bN && b[j] == c[i + j])
            )
        ) return true; 
        bool ok = false;
        if (i < aN && a[i] == c[i + j]) {
            ok |= f(i + 1, j, a, b, c, dp, aN, bN, cN);
        } 
        if (j < bN && b[j] == c[i + j]) {
            ok |= f(i, j + 1, a, b, c, dp, aN, bN, cN);
        }
        return dp[i][j] = ok;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int aN = s1.size(), bN = s2.size(), cN = s3.size();
        if (aN == 0 && bN == 0 && cN == 0) return true;
        if (aN + bN != cN) return false;
        vector<vector<int>> dp(aN + 1, vector<int> (bN + 1, -1));
        return f(0, 0, s1, s2, s3, dp, aN, bN, cN);
    }
};