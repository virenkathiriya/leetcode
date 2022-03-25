class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        vector<vector<int>> d = {
            {-1, 1},
            {-1, 0},
            {-1, -1},
            {0, -1},
            {0, 1},
            {1, 0},
            {1, -1},
            {1, 1}
        };
        
        int n = g.size();
        queue<pair<int, int>> q;
        if (n == 0 || g[0][0] == 1) return -1;
        q.push({0, 0});
        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        dp[0][0] = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first, y = it.second;
            for (int i = 0; i < 8; i++) {
                int xN = x + d[i][0], yN = y + d[i][1];
                if (xN < 0 || yN < 0 || xN >= n || yN >= n) continue;
                if (g[xN][yN] == 0 && dp[xN][yN] > dp[x][y] + 1) {
                    dp[xN][yN] = dp[x][y] + 1;
                    q.push({xN, yN});
                }
            }
        }
        return dp[n - 1][n - 1] == INT_MAX ? -1 : (dp[n - 1][n - 1] + 1);
    }
};