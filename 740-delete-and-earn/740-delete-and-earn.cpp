class Solution {
public:
    int deleteAndEarn(vector<int>& v) {
        int mx = *max_element(v.begin(), v.end()) + 1;
        vector<int> mp(mx, 0);
        for (int &x: v) {mp[x]++;}
        int i1 = mp[1], i2 = 0;
        for (int i = 2; i < mx; i++) {
            swap(i1, i2);
            i1 = max(i1 + mp[i] * i, i2);
        }
        return max(i1, i2);
    }
};