class Solution {
public:
    int rob(vector<int>& v) {
        int n = v.size();
        if (n == 1) return v[0];
        if (n == 2) return max(v[0], v[1]);
        int ans = 0;
        int i2 = v[0];
        int i1 = max(v[0], v[1]);
        for (int i = 2; i < n - 1; i++) {
            swap(i2, i1);
            i1 = max(i1 + v[i], i2);
        }
        ans = max(i2, i1);
        i2 = v[1];
        i1 = max(v[1], v[2]);
        for (int i = 3; i < n; i++) {
            swap(i2, i1);
            i1 = max(i1 + v[i], i2);
        }
        return max({ans, i1, i2});
    }
};