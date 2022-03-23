class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26, 0), f2(26, 0);
        for (char &c: s1) f1[c - 'a']++;
        
        int l = 0, r = 0, N = s2.size();
        while (l < N && r < N) {
            while (r < N && f2[s2[r] - 'a'] < f1[s2[r] - 'a']) {
                f2[s2[r] - 'a']++;
                r++;
            }
            bool ok = true;
            for (char &c: s1) {
                ok &= (f1[c - 'a'] == f2[c - 'a']);
                if (!ok) break;
            }
            if (ok) return true;
            if (r < N) {
                if (f1[s2[r] - 'a'] > 0) {
                    while (l < N && s2[l] != s2[r]) {
                        f2[s2[l] - 'a']--;
                        l++;
                    }
                    if (l < N && s2[l] == s2[r]) {
                        f2[s2[l] - 'a']--;
                        l++;
                    }
                } else {
                    r++;
                    while (l < N && l < r) {
                        if (f2[s2[l] - 'a'] > 0) f2[s2[l] - 'a']--;
                        l++;
                    }
                }
            }
        }
        return false;
    }
};