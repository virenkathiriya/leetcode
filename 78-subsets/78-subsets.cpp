class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& v) {
        int n = v.size();
        vector<int> path;
        for (int i = 0; i <= n; i++) { 
            rec(v, path, 0, i);
        }
        return ans;
    }
    
    void rec(vector<int> &v, vector<int> path, int l, int size) {
        if (path.size() == size) {
            ans.push_back(path);
            return;
        }
        for (int i = l; i < v.size(); i++) {
            path.push_back(v[i]);
            rec(v, path, i + 1, size);
            path.pop_back();
        } 
    }
};