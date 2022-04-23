class Solution {
public:
    int countNegatives(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int i = 0, j =  m - 1;
        int ans = 0;
        while (i < n && j >= 0) {
            if (g[i][j] >= 0) {
                i++;
                continue;
            }
            if (j > 0 && g[i][j - 1] < 0) {
                ans += (n - i);
                j--;
            } else {
                ans++;
                i++;
            }
        }
        return ans;
    }
};