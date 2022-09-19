class Solution {
public:
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> mp;
        for (string s: paths) {
            string prefix;
            int N = s.size();
            int i = 0;
            while (i < N && s[i] != ' ') {
                prefix += s[i];
                i++;
            }
            i++;
            while (i < N) {
                string path, content;
                while (i < N && s[i] != '(') {
                    path += s[i];
                    i++;
                }
                i++;
                while (i < N && s[i] != ')') {
                    content += s[i];
                    i++;
                }
                i += 2;
                mp[content].emplace_back(prefix + "/" + path);
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