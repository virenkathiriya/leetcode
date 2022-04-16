class Solution {
public:
    bool isAnagram(string a, string b) {
        vector<int> f1(26, 0), f2(26, 0);
        for (char &c: a) f1[c - 'a']++;
        for (char &c: b) f2[c - 'a']++;
        bool ok = true;
        for (int i = 0; i < 26; i++) {
            ok &= f1[i] == f2[i];
        }
        return ok;
    }
};