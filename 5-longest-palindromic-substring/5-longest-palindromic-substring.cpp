class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        int len = 1; int start = 0;
        for (int i = 0; i < n; i++) {dp[i][i] = true;}
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                start = i;
                len = 2;
                dp[i][i + 1] = true;
            }
        }
        for (int l = 3; l <= n; l++) {
            for (int j = 0; j + l - 1 < n; j++) {
                int right = j + l - 1;
                if (dp[j + 1][right - 1] && s[j] == s[right]) {
                    dp[j][right] = true;
                    if (len < l) {
                        len = l;
                        start = j;
                    }
                }
            }
        }
        return s.substr(start, len);
    }
};