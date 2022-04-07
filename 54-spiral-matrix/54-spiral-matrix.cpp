class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& g) {
        vector<int> ans;
        int n = g.size(), m = g[0].size();
        int i = 0, j = 0, cnt = 0, d = 0;
        while (cnt < m * n) {
            if (g[i][j] != 101) {
                ans.push_back(g[i][j]);
                g[i][j] = 101;
                cnt++;
            }
            switch (d) {
                case 0:
                    (j + 1 < m && g[i][j + 1] != 101) ? j++: d++;
                    break;
                case 1:
                    (i + 1 < n && g[i + 1][j] != 101) ? i++: d++;
                    break;
                case 2:
                    (j - 1 >= 0 && g[i][j - 1] != 101) ? j-- : d++;
                    break;
                case 3:
                    (i - 1 >= 0 && g[i - 1][j] != 101) ? i-- : d++;
                    break;
            }
            d %= 4;
        }
        return ans;
    }
};