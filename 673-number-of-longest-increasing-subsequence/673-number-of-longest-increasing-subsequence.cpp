class Solution {
public:
    int findNumberOfLIS(vector<int>& v) {
        int n = v.size();
        vector<vector<pair<int, int>>> vp(1, {{v[0], 1}});
        for (int i = 1; i < n; i++) {
            int l = 0, r = vp.size() - 1;
            int x = v[i];
            
            while (l < r) {
                int m = l + (r - l) / 2;
                if (vp[m].back().first >= x) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            
            if (l < n && vp[l].back().first < x) l++;
            int ind = l; // row position where it will be inserted
            if (ind == 0) {
                // we don't have previous row, so we. will just add it to end of this with len 1
                vp[0].emplace_back(x, vp[0].back().second + 1);
                continue;
            } 
            
            l = 0, r = vp[ind - 1].size() - 1;
            
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (vp[ind - 1][m].first >= x) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } 
            int greaterOrEqual = r;
            int count = vp[ind - 1].back().second - (greaterOrEqual == -1 ? 0: vp[ind - 1][greaterOrEqual].second);
            
            if (ind == vp.size())
                vp.push_back({{x, count}});
            else
                vp[ind].emplace_back(x, count + vp[ind].back().second);
        }
        return vp.back().back().second;
    }
};