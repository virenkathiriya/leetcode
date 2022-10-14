class Solution {
public:
    int f(vector<vector<int>>& g, vector<vector<vector<int>>> &dp, int r1, int c1, int c2, int N, int M) {
        int r2 = r1 + c1 - c2;
        if (r1 >= N or r2 >= N or c1 >= M or c2 >= M) return INT_MIN;
        if (g[r1][c1] == -1 or g[r2][c2] == -1) return INT_MIN;
        if (r1 == N - 1 and c1 == M - 1) return dp[r1][c1][c2] = g[r1][c1];
        if (dp[r1][c1][c2] != INT_MIN) return dp[r1][c1][c2];
        int cur = g[r1][c1] + ((c1 == c2) ? 0 : g[r2][c2]);
        cur += max({
            f(g, dp, r1, c1 + 1, c2 + 1, N, M),
            // r1, c1 -R> r1, c1 + 1 
            // r2, c2 -R> r2, c2 + 1
            f(g, dp, r1 + 1, c1, c2 + 1, N, M),
            // r1, c1 -D> r1 + 1, c1 
            // r2, c2 -R> r2, c2 + 1
            f(g, dp, r1, c1 + 1, c2, N, M),
            // r1, c1 -R> r1, c1 + 1 
            // r2, c2 -D> r2 + 1, c2
            f(g, dp, r1 + 1, c1, c2, N, M)
            // r1, c1 -D> r1 + 1, c1 
            // r2, c2 -D> r2 + 1, c2
        });
        return dp[r1][c1][c2] = cur;
    }
    
    int cherryPickup(vector<vector<int>>& g) {
        int N = g.size(), M = g[0].size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>> (M, vector<int> (M, INT_MIN)));
        return max(0, f(g, dp, 0, 0, 0, N, M));
    }
};