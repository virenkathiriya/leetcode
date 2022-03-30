class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sf(26, 0), pf(26, 0);
        for (char &c: p) pf[c - 'a']++;
        int l = 0, r = 0, n = s.length();
        vector<int> ans;
        while (r < n) {
            sf[s[r] - 'a']++;
            bool ok = true, faulty = false;;
            for (int i = 0; i < 26; i++) {
                ok &= sf[i] == pf[i];
                faulty |= (sf[i] > pf[i]);
            }
            if (ok) {
                ans.push_back(l);
                sf[s[l] - 'a']--;
                l++;
            } else if (faulty) {
                sf[s[l] - 'a']--;
                l++;
            }           
            r++;
        }
        return ans;
    }
};