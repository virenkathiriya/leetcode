class Solution {
public:
    int maxProfit(vector<int>& v) {
        int N = v.size(), rmax = 0, ans = 0;
        for (int i = N - 1; i >= 0; i--) {
            ans = max(ans, rmax - v[i]);
            rmax = max(rmax, v[i]);
        }
        return ans;
    }
};