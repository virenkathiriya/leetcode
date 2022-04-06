class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> f(26, 0), f1(26, 0);
        for (char &c: s) f[c - 'a']++;
        for (char &c: t) f1[c - 'a']++;
        for (int i = 0; i < 26; i++) if (f[i] != f1[i]) return i + 'a';
        return ' ';
    }
};