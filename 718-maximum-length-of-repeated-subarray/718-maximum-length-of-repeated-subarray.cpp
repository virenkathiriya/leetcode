class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (a[i] == b[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
                ans = max(dp[i][j], ans);
            }
        }
        return ans;
    }
};