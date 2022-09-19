class Solution {
public:
    vector<vector<string>> f(string s, int i, int n) {
        vector<vector<string>> ans;
        while (i < n) {
            string path, content;
            while (i < n && s[i] != '(') {
                path += s[i];
                i++;
            }
            i++;
            while (i < n && s[i] != ')') {
                content += s[i];
                i++;
            }
            i+=2;
            ans.push_back({path, content});
        }
        return ans;
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        for (string s: paths) {
            string prefix;
            int N = s.size();
            int i = 0;
            while (i < N && s[i] != ' ') {
                prefix += s[i];
                i++;
            }
            i++;
            for (vector<string> v: f(s, i, N)) {
                mp[v[1]].emplace_back(prefix + "/" + v[0]);
            }
        }
        vector<vector<string>> ans;
        for (auto it: mp) {
            if (it.second.size() > 1) {
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};