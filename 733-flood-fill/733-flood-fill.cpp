class Solution {
public:
    void dfs(vector<vector<int>>& g, int x, int y, int k) {
        int pre_v = g[x][y];
        g[x][y] = k;
        vector<int> X = {-1, 0, 1, 0}, Y = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int n_x = x + X[i], n_y = y + Y[i];
            if(n_x >= 0 && n_x < g.size() && n_y >= 0 && n_y < g[0].size()) {
                if(g[n_x][n_y] == pre_v && pre_v != k) {
                    dfs(g, n_x, n_y, k);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& g, int x, int y, int k) {
        dfs(g, x, y, k);
        return g;
    }
};