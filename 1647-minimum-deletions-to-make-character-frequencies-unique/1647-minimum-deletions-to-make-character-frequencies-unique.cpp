class Solution {
public:
    int minDeletions(string s) {
        vector<int> f(26, 0);
        for (char &c: s) f[c - 'a']++;
        map<int, int> mp;
        for (int i = 0; i < 26; i++) if (f[i] > 0) mp[f[i]]++;
        int ans = 0;
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            if (it -> second > 1) {
                if (it -> first - 1 > 0) 
                    mp[it -> first - 1] += it -> second - 1;
                ans += it -> second - 1;
            }
        }
        return ans;
    }
};