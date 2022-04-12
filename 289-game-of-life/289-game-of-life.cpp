class Solution {
public:
    
    void gameOfLife(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> di = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int live_count = 0;
                for (auto d: di) {
                    int x = i + d[0], y = j + d[1];
                    if (x < 0 || y < 0 || x >= n || y >= m) continue;
                    live_count += (g[x][y] & 1 == 1);
                }
                
                if (!g[i][j] && live_count == 3) g[i][j] |= 2;
                if (g[i][j] && live_count == 2 or live_count == 3) g[i][j] |= 2;
            }
        }
        
        for (auto &row: g) for (int &x: row) x >>= 1;
    }
};