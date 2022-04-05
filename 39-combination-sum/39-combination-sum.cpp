class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        rec(ans, v, path, target, 0, 0);
        return ans;
    }
    
    void rec(vector<vector<int>> &ans, vector<int> &v, vector<int> &path, int t, int sum, int l) {
        if (sum > t) return;
        if (sum == t) {
            ans.push_back(path);
            return;
        }
        for (int i = l; i < v.size(); ++i) {
            path.push_back(v[i]);
            sum += v[i];
            rec(ans, v, path, t, sum, i);
            sum -= v[i];
            path.pop_back();
        }
    }
};