class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, N = s.size(), ans = 0;
        vector<bool> f(256, false);
        if (N == 0) return 0;
        while (l < N && r < N) {
            while (!f[s[r]] && r < N) {
                f[s[r]] = true;
                r++;
                if (r == N) break;
            }
            ans = max(ans, r - l);
            if (r < N && f[s[r]]) {
                while (s[l] != s[r] && l < N) {
                    f[s[l]] = false;
                    l++;
                    if (l == N) break;
                }
                if (s[l] == s[r]) {
                    f[s[l]] = false;
                    l++;
                }
            }
        }
        return ans;
    }
};