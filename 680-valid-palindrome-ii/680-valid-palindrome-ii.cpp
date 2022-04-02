class Solution {
public:
    bool isPalindrome(string s) {
        int N = s.length();
        for (int i = 0; i < N / 2; i++) {
            if (s[i] != s[N - 1 - i]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int N = s.length();
        for (int i = 0; i < N / 2; i++) {
            if (s[i] == s[N - 1 - i]) continue;
            int len = N - i * 2 - 1;
            return isPalindrome(s.substr(i, len)) || isPalindrome(s.substr(i + 1, len));
        }
        return true;
    }
};