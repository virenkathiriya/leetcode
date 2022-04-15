class Solution {
public:
    bool ans;
    bool exist(vector<vector<char>>& g, string w) {
        int n = g.size(), m = g[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (f(g, i, j, 0, w, n, m)) return true;
            }
        }
        return false;
    }
                    
    bool f(vector<vector<char>>& g, int i, int j, int ptr, const string& w, const int &n, const int &m) {
        if (i < 0 || j < 0 || i >= n || j >= m || g[i][j] != w[ptr]) return false;
        if (ptr == w.size() - 1) return true;
        
        g[i][j] = '^';
        bool ok = f(g, i + 1, j, ptr + 1, w, n, m)
                | f(g, i - 1, j, ptr + 1, w, n, m)
                | f(g, i, j + 1, ptr + 1, w, n, m)
                | f(g, i, j - 1, ptr + 1, w, n, m);
        g[i][j] = w[ptr];
        return ok;
    }                
};