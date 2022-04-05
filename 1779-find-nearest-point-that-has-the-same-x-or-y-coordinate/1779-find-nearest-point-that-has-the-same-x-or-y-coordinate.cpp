class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& vp) {
        int mn = INT_MAX, ans = -1;
        for (int i = 0; i < vp.size(); i++) {
            if (vp[i][0] == x or vp[i][1] == y) {
                int dis = abs(vp[i][0] - x) + abs(vp[i][1] - y);
                if (mn > dis) {
                    mn = dis;
                    ans = i;
                }
            }
        }
        return ans;
    }
};