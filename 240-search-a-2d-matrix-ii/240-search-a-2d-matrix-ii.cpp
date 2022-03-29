class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int n = v.size();
        int m = v[0].size();
        for (auto &row: v) {
            if (row[0] <= t && row[m - 1] >= t) {
                int l = 0, r = m - 1;
                while (l <= r) {
                    int m = l + (r - l) / 2;
                    if (row[m] == t) return true;
                    if (row[m] > t) r = m - 1;
                    else l = m + 1;
                }
            }
        }
        return false;
    }
};