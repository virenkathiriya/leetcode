class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> ans;
        sort(v.begin(), v.end());
        for (auto it: v) {
            if (ans.empty() || ans.back()[1] < it[0]) {
                ans.push_back(it);
                continue;
            } 
            ans.back()[1] = max(ans.back()[1], it[1]);
        }
        return ans;
    }
};