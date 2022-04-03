class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> ans;
        vector<int> path;
        sort(v.begin(), v.end());
        rec(ans, v, path, 0);
        return ans;
    }
    
    void rec(vector<vector<int>> &ans, vector<int> &v, vector<int> &path, int start) {
        ans.push_back(path);
        for (int i = start; i < v.size(); ++i) {
            if (i == start || v[i] != v[i - 1]) {
                path.push_back(v[i]);
                rec(ans, v, path, i + 1);
                path.pop_back();
            }
        }
    }
};