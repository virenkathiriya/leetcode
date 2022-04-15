class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<int> cur(m + 1, 0);
        vector<int> prev(m + 1);
        if (n == 0 || m == 0) return abs(n - m);
        /*
         insert: dp[i][j] = dp[i][j - 1] + 1; 
         delete: dp[i][j] = dp[i - 1][j] + 1;
         transition: dp[i][j] = dp[i - 1][j - 1] + (a[i] == b[j] 1based indexing);
         
         base:::
         dp[0][j] --> trying to convert empty to b.substr(0, j + 1); we need j + 1 inserts
         dp[i][0] --> trying to convert a.substr(0, i + 1); we need i + 1 deletion
        **/
        iota(prev.begin(), prev.end(), 0);
        for (int i = 1; i <= n; i++) {
            cur[0] = i;
            for (int j = 1; j <= m; j++) {
                cur[j] = (a[i - 1] == b[j - 1]) ? (prev[j - 1]): (min({prev[j], cur[j - 1], prev[j - 1]}) + 1);
            }
            prev = cur;
        }
        return prev[m];
    }
};