class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                set<int> s;
                for (int k = 0; k < 3; k++) {
                    s.insert(g[i + k][j] + g[i + k][j + 1] + g[i + k][j + 2]); 
                    s.insert(g[i][j + k] + g[i + 1][j + k] + g[i + 2][j + k]);
                }
                s.insert(g[i][j] + g[i + 1][j + 1] + g[i + 2][j + 2]);
                s.insert(g[i + 2][j] + g[i + 1][j + 1] + g[i][j + 2]);
                
                set<int> uni;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        uni.insert(g[i + k][j + l]);
                    }
                }
                ans += (s.size() == 1 && uni.size() == 9 && *(uni.begin()) == 1 && *(uni.rbegin()) == 9);
            }
        }
        return ans;
    }
};