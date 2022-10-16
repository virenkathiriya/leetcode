class Solution {
public:
    int f(int i, int d, int N, vector<int>&v, vector<vector<int>> &dp) {
        if (d == 0 && i == N) return 0;
        if (d == 0 or i == N) return INT_MAX;
        if (dp[i][d] != INT_MAX) return dp[i][d];
        
        int res = INT_MAX;
        int _max = INT_MIN;
        for (int j = i; j < N; j++) {
            _max = max(_max, v[j]);
            
            int rem = f(j + 1, d - 1, N, v, dp);
            if (rem == INT_MAX) {
                continue;
            }
            res = min(res, _max + rem);
        }
        
        return dp[i][d] = res;
    }
    
    int minDifficulty(vector<int>& v, int d) {
        int N = v.size();
        if (N < d) return -1;
        vector<vector<int>> dp(N + 1, vector<int> (d + 1, INT_MAX));
        return f(0, d, N, v, dp);
    }
};