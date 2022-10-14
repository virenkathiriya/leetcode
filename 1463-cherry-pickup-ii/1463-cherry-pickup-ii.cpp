class Solution {
public:
    int f(vector<vector<int>>& g, vector<vector<vector<int>>> &dp, int i, int j1, int j2, int N, int M) {
        if (i >= N or j1 >= M or j2 >= M or j1 < 0 or j2 < 0) return INT_MIN;
        if (i == N - 1) 
            return dp[i][j1][j2] = g[i][j1] + ((j1 == j2) ? 0: g[i][j2]);
        
        if (dp[i][j1][j2] != INT_MIN) return dp[i][j1][j2];
        
        int cur = g[i][j1] + ((j1 == j2) ? 0: g[i][j2]);
        
        vector<int> d = {-1, 0, 1};
        int mx = INT_MIN;
        for (int _i = 0; _i < 3; _i++) 
            for (int j = 0; j < 3; j++)  
                mx = max(mx, f(g, dp, i + 1, j1 + d[_i], j2 + d[j], N, M));
        cur += mx;
        return dp[i][j1][j2] = cur;
    }
    
    int cherryPickup(vector<vector<int>>& g) {
        int N = g.size(), M = g[0].size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>> (M, vector<int> (M, INT_MIN)));
        return max(0, f(g, dp, 0, 0, M - 1, N, M));
    }
};