class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        // lps computation
        vector<int> lps(m, 0);
        for (int i = 1, len = 0; i < m;) (needle[i] == needle[len]) ? lps[i++] = ++len : ((len == 0) ? i++ : len = lps[len - 1]);
        // string matching
        for (int i = 0, j = 0; i < n;) {
            (haystack[i] == needle[j]) ? (i++, j++) : ((j == 0) ? i++ : (j = lps[j - 1]));
            if (j == m) return (i - j);
        }
        return -1;
    }
};