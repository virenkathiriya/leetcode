class Solution {
public:
    string breakPalindrome(string s) {
        int N = s.size();
        if (N == 1) return "";
        for (int i = 0; i < N / 2; i++) {
            if (s[i] != 'a') {
                s[i] = 'a';
                return s;
            }
        }
        s[N - 1] = 'b';
        return s;
    }
};