class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> ans = g;
        vector<vector<int>> di = {{0, 1}, {0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {1, 1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0, sum = 0;
                for (vector<int> &d: di) {
                    int X = i + d[0], Y = j + d[1];
                    if (X < 0 || Y < 0 || X >= n || Y >= m) continue;
                    cnt++;
                    sum += g[X][Y];
                }
                ans[i][j] |= (sum / cnt) << 8;
            }
        }
        for (auto &y: ans) for (int &x: y) x >>= 8; 
        return ans;
    }
};