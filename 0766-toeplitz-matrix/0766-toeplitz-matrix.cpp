class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& g) {
        bool ok = true;
        int N = g.size(), M = g[0].size();
        for (int i = 0; i < N - 1; ++i) {
            for (int j = 0; j < M - 1; ++j) {
                ok &= g[i][j] == g[i + 1][j + 1];
            }
        }
        return ok;
    }
};