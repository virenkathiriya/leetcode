class Solution {
public:
    int maxProduct(vector<int>& v) {
        int mn = 1, mx = 1, ans = v[0];
        int n = v.size();
        for (int &x: v) {
            if (x < 0) swap(mn, mx);
            mn = min(x * mn, x);
            mx = max(x * mx, x);
            ans = max(ans, mx);
        }
        return ans;
    }
};