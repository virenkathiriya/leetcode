class Solution {
public:
    int surfaceArea(vector<vector<int>>& g) {
        int n = g.size();
        int ans = 2 * n * n; // bottom + top views
        // if its one of the outer cubes let their non-existing neighbour be 0;
        // approach will be to count only if the current value is larger then the neighbour
        int cnt_0 = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int l, r, t, b;
                l = r = t = b = 0;
                int c = g[i][j];
                if(c == 0) {
                    cnt_0++;
                    continue;
                }
                b = (i + 1 < n) ? g[i + 1][j] : 0;    
                t = (i - 1 >= 0) ? g[i - 1][j] : 0;  
                r = (j + 1 < n) ? g[i][j + 1] : 0;    
                l = (j - 1 >= 0) ? g[i][j - 1] : 0;     
                ans += max(c - t, 0) + max(c - r, 0) + max(c - b, 0) + max(c - l, 0);
            }
        }
        return ans - cnt_0 * 2;
    }
};