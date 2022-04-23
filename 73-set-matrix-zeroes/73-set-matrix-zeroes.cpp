class Solution {
public:
    void setZeroes(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        bool col = false;
        for (int i = 0; i < n; i++) {
            if (g[i][0] == 0) col = true;
            for (int j = 1; j < m; j++) {
                if (g[i][j] == 0) {
                    g[i][0] = g[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++) for (int j = 1; j < m; j++) if (g[i][0] == 0 || g[0][j] == 0) g[i][j] = 0;
        if (g[0][0] == 0) for (int j = 0; j < m; j++) g[0][j] = 0;
        if (col) for (int i = 0; i < n; i++) g[i][0] = 0;
    }
};