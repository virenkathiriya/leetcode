class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> mp;
        unordered_map<char, string> mp1;
        
        int i = 0, n = s.length();
        string word;
        char deflt = mp["hell yeah"];
        for (char &c: pattern) {
            if (i >= n) return false;
            while (i < n && s[i] != ' ') word += s[i++];
            i++;
            if (mp[word] == deflt && mp1[c] == "") {mp[word] = c; mp1[c] = word;}
            else if (mp[word] != c) return false;
            word.clear();
        }
        return i >= n;
    }
};