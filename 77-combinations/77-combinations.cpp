class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        rec(n, k, 1, {}, ans);
        return ans;
    }
    
    void rec(int n, int k, int cur_ptr, vector<int> cur_combination, vector<vector<int>> &ans) {
        if (k == 0) {
            ans.push_back(cur_combination);
            return;
        }
        
        if (k <= n - cur_ptr)
            rec(n, k, cur_ptr + 1, cur_combination, ans);
        cur_combination.push_back(cur_ptr);
        rec(n, k - 1, cur_ptr + 1, cur_combination, ans);
    }
};