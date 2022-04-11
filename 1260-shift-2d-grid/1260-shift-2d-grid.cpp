class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
        int n = g.size();
        int m = g[0].size();
        k %= (n * m);
        vector<vector<int>> ans(n, vector<int> (m, 1001));
        int x = k / m, y = k % m;
        int i = 0, j = 0;
        while (ans[x][y] == 1001) {
            ans[x][y] = g[i][j];
            if (j + 1 == m) {
                j = 0;
                i = (i + 1) % n;
            } else j++;
            
            if (y + 1 == m) {
                y = 0;
                x = (x + 1) % n;
            } else y++;
        }
        return ans;
    }
};