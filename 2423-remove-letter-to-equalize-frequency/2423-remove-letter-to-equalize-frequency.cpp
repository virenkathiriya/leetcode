class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> f(26, 0);
        for(char c: word) f[c - 'a']++;
        sort(f.rbegin(), f.rend());
        for (int i = 0; i < 26; i++) {
            f[i]--;
            bool ok = true;
            vector<int> x(f.begin(), f.end());
            sort(x.rbegin(), x.rend());
            for (int j = 0; j < 26; j++) ok &= (x[0] == x[j] || x[j] == 0);
            f[i]++;
            if (ok) return ok;
        }
        return false;
    }
};