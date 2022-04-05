class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& v) {
        vector<vector<int>> ans;
        int n = v.size();
        rec(v, ans, n, 0);
        return ans;
    }
    
    void rec(vector<int> &v, vector<vector<int>> &ans, int &n, int start) {
        if (start == n) {
            ans.push_back(v);
            return;
        }
        vector<int> seen(21, 0);
        for (int i = start; i < n; i++) {
            swap(v[i], v[start]);
            if (seen[v[start] + 10] == 0) {
                rec(v, ans, n, start + 1);
                seen[v[start] + 10] = 1;
            }
            swap(v[i], v[start]);
        }
    }
};