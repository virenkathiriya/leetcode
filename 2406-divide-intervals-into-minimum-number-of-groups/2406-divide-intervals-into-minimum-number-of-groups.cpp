class Solution {
public:
    int minGroups(vector<vector<int>>& v) {
        int N = v.size();
        vector<pair<int, char>> vp;
        for (int i = 0; i < N; i++) {
            vp.push_back({v[i][0], 'x'});
            vp.push_back({v[i][1], 'y'});
        }
        sort(vp.begin(), vp.end());
        int ans = 0, cur = 0;
        for (auto &it: vp) {
            if (it.second == 'x') cur++;
            if (it.second == 'y') cur--;
            ans = max(ans, cur);
        }
        return ans;
    }
};