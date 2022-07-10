class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mp(256, -1);
        vector<bool> mapped(256, false);
        for (int i = 0; i < s.length(); i++) {
            if (mp[s[i]] != -1) {
                if (t[i] == mp[s[i]]) continue;
                return false;
            } else {
                if (mapped[t[i]] && mp[s[i]] != t[i]) return false;
                mp[s[i]] = t[i];
                mapped[t[i]] = true;
            }
        }
        return true;
    }
};