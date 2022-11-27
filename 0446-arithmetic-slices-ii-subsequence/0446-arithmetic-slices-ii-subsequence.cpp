class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        int N = v.size();
        vector<map<int, int>> dp(N);
        
        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if ((long)v[i] - (long)v[j] > INT_MAX || (long)v[i] - (long)v[j] < INT_MIN) continue;

                int d = v[i] - v[j];
                dp[i][d]++;
                
                if(dp[j].find(d) != dp[j].end()) {
                    dp[i][d] += dp[j][d];
                    res += dp[j][d];
                }
            }
        }
        return res;
    }
};