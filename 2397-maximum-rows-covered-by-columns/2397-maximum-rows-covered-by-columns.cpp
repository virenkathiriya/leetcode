class Solution {
public:
    int maximumRows(vector<vector<int>>& g, int cols) {
        int n = g.size(), m = g[0].size();
        int ans = 0;
        for (int i = 0; i < (1 << m); i++) {
            if (__builtin_popcount(i) == cols) {
                int cnt = 0;
                for (int r = 0; r < n; r++) {
                    bool ok = true;
                    for (int c = 0; c < m; c++) {
                        if (g[r][c] == 1) {
                            ok &= ((i & (1 << c)) > 0);
                        }
                    }
                    cnt += ok;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};