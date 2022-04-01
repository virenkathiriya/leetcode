class Solution {
public:
    int maxProfit(vector<int>& v) {
        int ans = 0, N = v.size();
        for (int i = 1; i < N; i++) {
            ans += max(0, v[i] - v[i - 1]);
        }
        return ans;
    }
};