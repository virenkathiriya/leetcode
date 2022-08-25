class Solution {
public:
    bool canConstruct(string a, string b) {
        vector<int> f(26, 0);
        for (char &c: b) f[c - 'a']++;
        for (char &c: a) {
            f[c - 'a']--;
            if (f[c - 'a'] < 0) return false;
        }
        return true;
    }
};