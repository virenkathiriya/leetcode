class Solution {
public:
    int minimumWhiteTiles(string floor, int nC, int cL) {
        int N = floor.size();
        vector<int> s(N, 0);
        vector<vector<int>> dp(N + 1, vector<int> (nC + 1, 0));
        s[N - 1] = floor[N - 1] == '1';
        for (int i = N - 2; i >= 0; i--) s[i] = s[i + 1] + (floor[i] == '1');
        for (int i = 0; i < N; i++) dp[i][0] = s[i];
        for (int i = N - 1; i >= 0; i--) for (int j = 1; j <= nC; j++) dp[i][j] = min(i + cL > N ? 0 : dp[i + cL][j - 1], (floor[i] == '1') + dp[i + 1][j]);
        return dp[0][nC];
    }
};