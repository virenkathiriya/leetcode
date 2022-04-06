class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> v(n, vector<int> (26, 0));
        for (int i = 0; i < n; i++) {
            if (i) {
                for (int j = 0; j < 26; j++) v[i][j] = v[i - 1][j];
            }
            v[i][s[i] - 'a']++;
        }
        
        vector<int> f(26, -1), l(26, -1);
        for (int i = 0; i < n; i++) {
            if (f[s[i] - 'a'] == -1) f[s[i] - 'a'] = i;
            if (l[s[n - 1- i] - 'a'] == -1) l[s[n - 1 - i] - 'a'] = n - 1 - i;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (l[i] > f[i]) {
                for (int k = 0; k < 26; k++) {
                    ans += (v[l[i] - 1][k] - v[f[i]][k] > 0);
                }
            }
        }
        return ans;
    }
};