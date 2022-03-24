class Solution {
public:
    bool searchMatrix(vector<vector<int>>& g, int t) {
        int n = g.size(), m = g[0].size();
        
        // find row through binary search
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (g[m][0] == t) return true;
            if (g[m][0] > t) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        if (r < 0) return false;
        
        // r will be our row;
        int row = r;
        l = 0, r = m - 1;
         while (l <= r) {
            int m = l + (r - l) / 2;
            if (g[row][m] == t) return true;
            if (g[row][m] > t) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
    
        return false;
    }
};