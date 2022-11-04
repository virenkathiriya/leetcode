class Solution {
public:
    bool f(char c) {
        if (!isalpha(c)) return false;
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseVowels(string s) {
        int N = s.size();
        int i = 0, j = N - 1;
        while (i < j) {
            while (!f(s[i]) && i < N) ++i;
            while (!f(s[j]) && j > 0) --j;
            if (i >= j) break;
            swap(s[i], s[j]);
            i++, j--;
        }
        return s;
    }
};