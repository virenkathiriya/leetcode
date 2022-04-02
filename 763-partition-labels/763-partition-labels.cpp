class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> f(26, 0);
        for (char &c: s) f[c - 'a']++;
        
        vector<int> cur(26, 0);
        vector<int> ans;
        int cnt = 0;
        for (char &c: s) {
            int x = c - 'a';
            cnt++;
            cur[x]++;
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (cur[i] == 0) continue;
                ok &= cur[i] == f[i];
                if (!ok) break;
            }
            if (ok) {
                ans.push_back(cnt);
                cnt = 0;
            }
        }
        return ans;
    }
};