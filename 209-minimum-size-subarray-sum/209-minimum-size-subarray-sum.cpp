class Solution {
public:
    int minSubArrayLen(int t, vector<int>& v) {
        int sum = 0;
        int n = v.size();
        int l = 0;
        int ans = INT_MAX;
        for (int r = 0; r < n; r++) {
            sum += v[r];
            while (sum >= t) ans = min(ans, r - l + 1), sum -= v[l++];
        }
        return ans == INT_MAX ? 0 : ans;
    }
};