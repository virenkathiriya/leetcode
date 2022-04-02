class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void dfs(int u, vector<vector<int>>& g, vector<int> &cur) {
        cur.push_back(u);
        if (u == n) 
            ans.push_back(cur);
        else
            for (int &x: g[u]) dfs(x, g, cur);
        cur.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        n = g.size() - 1;
        vector<int> cur;
        dfs(0, g, cur);
        return ans;
    }
};