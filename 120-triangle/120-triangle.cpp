class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        int n = v.size();
        if (n == 1) return v[0][0];
        int ans = INT_MAX;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                if (j == 0) v[i][j] += v[i - 1][0];
                else if (j == v[i].size() - 1) v[i][j] += v[i - 1][j - 1];
                else v[i][j] += min (v[i - 1][j - 1], v[i - 1][j]);
                if (i == n - 1) {
                    ans = min(ans, v[i][j]);
                }
            }
        }
        return ans;
    }
};