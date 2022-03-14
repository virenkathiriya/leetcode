class Solution {
public:
    int maxProfit(vector<int>& v) {
        int N = v.size();
        vector<int> l(N, 0), r(N, 0);
        l[0] = v[0], r[N - 1] = v[N - 1];
        for (int i = 1; i < N; i++) l[i] = min(l[i - 1], v[i]);
        for (int i = N - 2; i >= 0; i--) r[i] = max(r[i + 1], v[i]);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans = max(ans, r[i] - l[i]);
        }
        return ans;
    }
};