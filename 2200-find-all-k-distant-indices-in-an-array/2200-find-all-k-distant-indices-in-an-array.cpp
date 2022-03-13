class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& v, int key, int k) {
        int n = v.size();
        vector<bool> vis(n, 0);
        for(int i = 0; i < n; i++) {
            if(v[i] == key) {
                int j = 1;
                vis[i] = true;
                while(j <= k) {
                    if(i + j < n)
                        vis[i + j] = true;
                    if(i - j >= 0)
                        vis[i - j] = true;
                    j++;
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(vis[i]) ans.push_back(i);
        }
        return ans;
    }
};