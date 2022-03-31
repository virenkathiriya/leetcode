class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> f(256, 0);
        bool odd = false;
        for (char &c: s) f[c]++;
        int len = 0;
        for (int i = 0; i < 256; i++) {
            len += f[i] / 2;
            odd |= f[i] % 2;
        }
        return len * 2 + odd;
    }
};