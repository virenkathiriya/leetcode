class Solution {
public:
    int f(vector<int> &v, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j]) return dp[i][j];
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int cost = f(v, i, k, dp) + v[i] * v[k] * v[j] + f(v, k, j, dp);
            ans = min(cost, ans);
        }
        return dp[i][j] = (ans == INT_MAX ? 0 : ans);
    }
    
    int minScoreTriangulation(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return f(v, 0, n - 1, dp);
    }
};