class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        for (int i = 1, j = 0; i < n;) {
            if (s[i] == s[j]) lps[i++] = ++j;
            else {
                if (j == 0) i++;
                else j = lps[j - 1];
            }
        }
        return lps[n - 1] && (lps[n - 1] % (n - lps[n - 1]) == 0);
    }
};