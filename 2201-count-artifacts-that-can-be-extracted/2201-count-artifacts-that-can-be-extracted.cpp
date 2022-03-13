class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& v, vector<vector<int>>& dig) {
        int cnt = 0;
        vector<vector<int>> digged(n, vector<int> (n, 0));
        for(int i = 0; i < dig.size(); i++) {
            digged[dig[i][0]][dig[i][1]] = true;
        }
        for(vector<int> &u: v) {
            int x1 = u[0], y1 = u[1], x2 = u[2], y2 = u[3];
            bool ok = true;
            for(int i = x1; i <= x2 && ok; i++) {
                for(int j = y1; j <= y2 && ok; j++) {
                    ok &= digged[i][j];
                }
            }
            cnt += ok;
        }
        return cnt;
    }
};