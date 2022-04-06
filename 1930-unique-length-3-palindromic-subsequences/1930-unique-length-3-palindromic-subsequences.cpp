class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> f(26, -1), l(26, -1);
        for (int i = 0; i < n; i++) {
            if (f[s[i] - 'a'] == -1) f[s[i] - 'a'] = i;
            if (l[s[n - 1- i] - 'a'] == -1) l[s[n - 1 - i] - 'a'] = n - 1 - i;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (l[i] > f[i]) {
                vector<bool> b(26, false); 
                int cnt = 0;
                for (int j = f[i] + 1; j < l[i]; j++) {if (!b[s[j] - 'a']) {b[s[j] - 'a'] = true; cnt++;} if(cnt >= 26) break;}
                ans += accumulate(b.begin(), b.end(), 0);
            }
        }
        return ans;
    }
};