class Solution {
public:
    bool searchMatrix(vector<vector<int>>& g, int t) {
        int i = 0, j = 0;
        int n = g.size(), m = g[0].size();
        while (i < n && j < m) {
            if (g[i][j] == t) return true;
            if (g[i][j] > t) return false;
            if (i + 1 < n) {
                if (g[i + 1][j] > t) { 
                    j++;
                } else {
                    i++;
                }
                continue;
            }
            if (j + 1 < m) {
                if (g[i][j + 1] > t) { 
                    return false;
                } else {
                    j++;
                    continue;
                }
            }
            return false;
        }
        return false;
    }
};