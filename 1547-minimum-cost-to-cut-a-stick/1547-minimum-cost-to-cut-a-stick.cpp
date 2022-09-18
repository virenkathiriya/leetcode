class Solution {
public:
    int minCost(int n, vector<int>& v) {
        int m = v.size();
        v.push_back(n);
        v.insert(v.begin(), 0);
        sort(v.begin(), v.end());
        vector<vector<int>> dp(m + 2, vector<int> (m + 2, 0));
        for (int i = m; i >= 1; i--) {
            for (int j = 1; j <= m; j++) {
                if (i > j) continue;
                int ans = INT_MAX;
                for (int k = i; k <= j; k++) {
                    ans = min(ans, v[j + 1] - v[i - 1] + dp[i][k - 1] + dp[k + 1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][m];
    }
};