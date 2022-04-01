class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int cur_max = 0, n = v.size(), ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, cur_max + v[i] - i);
            cur_max = max(cur_max, v[i] + i);
        }
        return ans;
    }
};