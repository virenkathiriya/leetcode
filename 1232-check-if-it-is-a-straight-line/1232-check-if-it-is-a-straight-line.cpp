class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& vp) {
        double slope = -1;
        for (int i = 0; i < vp.size() - 1; i++) {
            double s;
            if (vp[i + 1][0] - vp[i][0] == 0) s = INT_MAX;
            else s = (vp[i + 1][1] - vp[i][1]) * 1. / (vp[i + 1][0] - vp[i][0]);
            if (slope == -1) {
                slope = s;
                continue;
            }
            if (slope != s) return false;
        }
        return true;
    }
};