class Solution {
public:
    vector<int> findOriginalArray(vector<int>& v) {
        vector<int> ans;
        
        int N = v.size();
        if (N % 2) return {};
        sort(v.begin(), v.end());
        
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < N; ++i) mp[v[i]].push_back(i + 1);
        
        for (int i = 0; i < N; i++) {
            if (v[i] < 0) continue;
            int e = v[i] * 2;
            if (mp[e].size() > 0) {
                int index = mp[e].back();
                mp[e].pop_back();
                ans.push_back(v[i]);
                v[index - 1] = -1;
            } else {
                return {};
            }
        }
        if (ans.size() == N / 2) return ans;
        return {};
    }
};