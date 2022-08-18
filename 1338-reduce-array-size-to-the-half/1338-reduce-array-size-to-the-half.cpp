class Solution {
public:
    int minSetSize(vector<int>& v) {
        int mx = *max_element(v.begin(), v.end());
        vector<int> f(mx + 1, 0);
        for (int &x: v) f[x]++;
        sort(f.begin(), f.end(), greater<>());
        int ans = 0;
        for (int i = 0; i <= mx; ++i) {
            ans += f[i];
            if (ans >= (v.size() / 2)) return i + 1;
        }
        return -1;
    }
};