class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void dfs(int u, vector<vector<int>>& g, vector<int> cur) {
        cur.push_back(u);
        if (u == n) {
            ans.push_back(cur);
            return;
        }
        for (int &x: g[u]) {
            dfs(x, g, cur);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        n = g.size() - 1;
        dfs(0, g, {});
        return ans;
    }
};