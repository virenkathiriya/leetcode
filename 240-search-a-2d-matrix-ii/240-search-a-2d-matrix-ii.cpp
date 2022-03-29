class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int n = v.size(), m = v[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (v[i][j] > t) j--;
            else if (v[i][j] < t) i++;
            else return true;
        }
        return false;
    }
};