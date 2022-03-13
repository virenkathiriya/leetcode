class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        if (v.size() == 1) return v;
        int N = v.size(), MX = 10002;
        
        vector<int> p(MX, 0), single(MX, 0);
        vector<vector<int>> ans; 
        for (int i = 0; i < N; i++) {
            if (v[i][0] == v[i][1]) 
                single[v[i][0]] = 1;
            else {
                p[v[i][0]]++; 
                p[v[i][1]]--;
            }
        }
        for (int i = 1; i < MX; i++) p[i] += p[i - 1];
        
        int l = -1, r = -1;
        for (int i = 0; i < MX; i++) {
            bool ending = false;
            if (p[i] == 0) {
                if (l != -1) {
                    ans.push_back({l, i});
                    ending = true;
                    l = r = -1;
                }
            } else if (l == -1) {
                l = i;
            }
            if (single[i]) {
                if (l == -1 && !ending) 
                    ans.push_back({i, i});
            }  
        }
        return ans;
    }
};