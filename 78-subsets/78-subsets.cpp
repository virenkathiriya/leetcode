class Solution {
public:
    vector<vector<int>> subsets(vector<int>& v) {
        int n = v.size();
        vector<int> path;
        vector<vector<int>> ans;
        rec(ans, v, path, 0);
        return ans;
    }
    
    void rec(vector<vector<int>> &ans, vector<int> &v, vector<int> path, int l) {
        ans.push_back(path);
        for (int i = l; i < v.size(); i++) {
            path.push_back(v[i]);
            rec(ans, v, path, i + 1);
            path.pop_back();
        } 
    }
};