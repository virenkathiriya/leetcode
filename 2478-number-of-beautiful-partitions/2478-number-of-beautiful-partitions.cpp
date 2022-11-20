class Solution {
public:
    const int M = 1000000007;
    int mn = 0;
    
    bool isP(char c) {
        return c == '2' or c == '3' or c == '5' or c == '7';
    }
    
    long long f(int i, int k, string &s, vector<vector<long long>> &dp) {
        int N = s.size();
        if (i == N) return k == 0 && !isP(s[N - 1]);
        if (k < 0 || !isP(s[i])) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        
        long long ans = 0;
        for (int j = i + mn - 1; j < N; ++j) if (!isP(s[j]) && (N - j + 1) >= (k - 1) * mn) ans = (ans + f(j + 1, k - 1, s, dp)) % M;
        return dp[i][k] = ans;
    }
    
    int beautifulPartitions(string s, int k, int minLength) {
        mn = minLength;
        int N = s.size();
        vector<vector<long long>> dp(N, vector<long long> (k + 1, -1));
        return f(0, k, s, dp);
    }
};