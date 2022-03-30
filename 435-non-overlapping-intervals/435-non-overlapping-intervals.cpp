class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& vp) {
        sort(vp.begin(), vp.end(), [&](const auto &it1, const auto &it2) {return it1[1] < it2[1];});
        vector<int> cur = vp[0];
        int ans = 0;
        for (int i = 1; i < vp.size(); i++) {
            if (vp[i][0] < cur[1]) ans++; 
            else cur = vp[i];
        }
        return ans;
    }
};