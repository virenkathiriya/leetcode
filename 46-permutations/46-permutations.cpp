class Solution {
public:
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>> ans;
        int n = v.size();
        vector<bool> vis(n, false);
        f(n, v, {}, vis, 0, ans);
        return ans;
    }
    
    void f(int &n, vector<int> &v, vector<int> cur_p, vector<bool> vis, int index, vector<vector<int>> &ans) {
        if (index == n) {
            ans.push_back(cur_p);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> cur_p_with_i_included(cur_p.begin(), cur_p.end());
                cur_p_with_i_included.push_back(v[i]);
                vector<bool> cur_vis_with_i_included(vis.begin(), vis.end());
                cur_vis_with_i_included[i] = true;
                f(n, v, cur_p_with_i_included, cur_vis_with_i_included, index + 1, ans);
            }
        }
    }
};