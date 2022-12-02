class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> f1(26, 0), f2(26, 0);
        set<char> s1, s2;
        for (char &c: word1) {f1[c - 'a']++; s1.insert(c);}
        for (char &c: word2) {f2[c - 'a']++; s2.insert(c);}
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        return f1 == f2 and s1 == s2;
    }
};