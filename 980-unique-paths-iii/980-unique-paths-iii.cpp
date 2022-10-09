class Solution {
public:
    int ans = 0;
    void f(vector<vector<int>>& g, int i, int j, int& n, int& m, int& e) {
        if (i >= n or j >= m or i < 0 or j < 0 or g[i][j] < 0) return;
        if (g[i][j] == 2) { 
            ans += (e == 0);
            return;
        }
        g[i][j] = -2;
        e--;
        f(g, i + 1, j, n, m, e);
        f(g, i - 1, j, n, m, e);
        f(g, i, j + 1, n, m, e);
        f(g, i, j - 1, n, m, e);
        g[i][j] = 0;
        e++;
    }
    
    int uniquePathsIII(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        pair<int, int> s;
        int e = 1;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1) 
                    s = {i, j}; 
                else if (g[i][j] == 0)
                    e++;
            }
        f(g, s.first, s.second, n, m, e);
        return ans;
    }
};