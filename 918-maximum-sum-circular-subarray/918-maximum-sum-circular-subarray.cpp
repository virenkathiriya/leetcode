class Solution {
public:
    int maxSubarraySumCircular(vector<int>& v) {
        int ans = INT_MIN, n = v.size();
        if (n == 1) return v[0];
        int sum = accumulate(v.begin(), v.end(), 0);
        int cur = INT_MIN, mx = INT_MIN;
        for (int &x: v) {
            cur = x + max(cur, 0);
            mx = max(cur, mx);
        }
        ans = max(ans, mx);
        
        cur = INT_MAX; int mn = INT_MAX;
        for (int i = 1; i < n; ++i) {
            cur = v[i] + min(cur, 0);
            mn = min(mn, cur);
        }
        ans = max(ans, sum - mn);
        
        cur = INT_MAX, mn = INT_MAX;
        for (int i = 0; i < n - 1; ++i) {
            cur = v[i] + min(cur, 0);
            mn = min(mn, cur);
        }
        return max(ans, sum - mn);
    }
};