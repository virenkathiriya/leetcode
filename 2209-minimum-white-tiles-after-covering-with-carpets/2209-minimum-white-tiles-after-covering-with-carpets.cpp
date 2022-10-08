class Solution {
public:
    int f(string &floor, vector<int> &s, int i, int n, int nC, int cL, vector<vector<int>> &dp) {
        if (i >= n) return 0;
        if (dp[i][nC] != -1) return dp[i][nC];
        if (nC == 0) return dp[i][nC] = s[i];
        int painted = f(floor, s, i + cL, n, nC - 1, cL, dp);
        int notPainted = (floor[i] == '1') + f(floor, s, i + 1, n, nC, cL, dp);
        return dp[i][nC] = min(painted, notPainted);
    }
    
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int N = floor.size();
        vector<int> s(N, 0);
        vector<vector<int>> dp(N, vector<int> (numCarpets + 1, -1));
        s[N - 1] = floor[N - 1] == '1';
        for (int i = N - 2; i >= 0; i--) s[i] = s[i + 1] + (floor[i] == '1');
        return f(floor, s, 0, N, numCarpets, carpetLen, dp);
    }
};