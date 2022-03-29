class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> ans;
        int n = a.size(), m = b.size(), i = 0, j = 0;
        while (i < n && j < m) {
            // check intersection, if exist add to ans
            int l = max(a[i][0], b[j][0]), r = min(a[i][1], b[j][1]);
            if (l <= r) ans.push_back({l, r});
            
            // discard smallest enpoint interval
            (r == a[i][1]) ? i++: j++;
        }
        return ans;
    }
};