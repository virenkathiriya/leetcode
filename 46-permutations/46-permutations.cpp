class Solution {
public:
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>> ans;
        int n = v.size();
        f(v, ans, 0, n);
        return ans;
    }
    
    void f(vector<int> v, vector<vector<int>> &ans, int l, int r) {
        if (l == r) {
            ans.push_back(v);
            return;
        }
        for (int i = l; i < r; i++) {
            swap(v[i], v[l]);
            f(v, ans, l + 1, r);
            swap(v[i], v[l]);
        }
    }
};