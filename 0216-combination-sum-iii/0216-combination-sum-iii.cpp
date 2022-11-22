class Solution {
public:
    void f(int k, int sum, int target, vector<int> &cur, vector<vector<int>> &ans) {
        if (k < 0) return;
        if (k == 0 && sum == target) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = (cur.size() == 0) ? 1: (cur.back() + 1); i < 10; i++) {
            cur.push_back(i);
            f(k - 1, sum + i, target, cur, ans);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        f(k, 0, n, cur, ans);
        return ans;
    }
};