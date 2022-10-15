class Solution {
public:
    int h (int x) { return (x == 0) ? 0 : (x == 1) ? 1 : (x < 10) ? 2 :(x < 100) ? 3 : 4; }
    
    int f (string &s, vector<vector<int>> &dp, int i, int k, int N) {
        if (i >= N || N - i <= k) return 0;
        if (dp[i][k] != INT_MAX) return dp[i][k];
        
        vector<int> fr(26, 0);
        int most_frequent = 0, ans = INT_MAX;
        for (int j = i; j < N; j++) {
            fr[s[j] - 'a']++;
            if (most_frequent < fr[s[j] - 'a']) {
                most_frequent = fr[s[j] - 'a'];
                int deletionRequired = (j - i + 1 - most_frequent);
                if (k >= deletionRequired) {
                    int score = f(s, dp, j + 1, k - deletionRequired, N);
                    if (score == INT_MAX) continue;
                    ans = min(ans, h(most_frequent) + score);
                }
            }
        }
        return dp[i][k] = ans;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        int N = s.size();
        vector<vector<int>> dp(N + 1, vector<int> (k + 1, INT_MAX));
        return f(s, dp, 0, k, N);
    }
};