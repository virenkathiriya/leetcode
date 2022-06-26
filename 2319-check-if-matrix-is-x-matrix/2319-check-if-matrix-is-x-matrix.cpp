class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& g) {
        int n = g.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i + j == n - 1) {
                    if (g[i][j] == 0) 
                        return false;
                }
                    
                else if (g[i][j] != 0) return false;
            }
        }
        return true;
    }
};