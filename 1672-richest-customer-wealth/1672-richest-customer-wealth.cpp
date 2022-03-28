class Solution {
public:
    int maximumWealth(vector<vector<int>>& v, int ans = 0) {
        for (int i = 0; i < v.size(); i++) ans = max(ans, accumulate(v[i].begin(), v[i].end(), 0));
        return ans;
    }
};