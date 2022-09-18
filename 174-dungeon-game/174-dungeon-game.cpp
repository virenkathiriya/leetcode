class Solution {
public:
    int z(int whatWeHave, int whatWeRequire) {
        if (whatWeHave >= whatWeRequire) return 1;
        return whatWeRequire - whatWeHave;
    }
    
    int f(vector<vector<int>>& g, vector<vector<int>>& dp, int i, int j, int n, int m) {
        if (i == n - 1 && j == m - 1) {
            return dp[i][j] = g[i][j] > 0 ? 1 : z(g[i][j], 1);
        }
        if (dp[i][j] != INT_MIN) return dp[i][j];
        
        if (j == m - 1) {
            return dp[i][j] = z(g[i][j], f(g, dp, i + 1, j, n, m));
        }
        if (i == n - 1) {
            return dp[i][j] = z(g[i][j], f(g, dp, i, j + 1, n, m));
        }
        
        int d = z(g[i][j], f(g, dp, i + 1, j, n, m));
        int r = z(g[i][j], f(g, dp, i, j + 1, n, m));
        return dp[i][j] = min(d, r);
    }
    
    int calculateMinimumHP(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, INT_MIN));
        return f(g, dp, 0, 0, n, m);
    }
    
    /*
     * f(i, j) -> health required to reach bottom-right (m - 1, n - 1) form (i, j);
     * base: i == n - 1, j == m - 1: return g[i][j];
     *       calculate who requires less [right, down!];
    **/ 
};