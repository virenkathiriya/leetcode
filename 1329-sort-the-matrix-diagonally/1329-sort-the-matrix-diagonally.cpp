class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& g) {
        int N = g.size(), M = g[0].size();
        map<int, vector<int>> mp;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                mp[i - j].push_back(g[i][j]);
            }
        }
        map<int, int> ind;
        for (auto &[_, v]: mp) sort(v.begin(), v.end());
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                g[i][j] = mp[i - j][ind[i - j]];
                ind[i - j]++;
            }
        }
        return g;
    }
};