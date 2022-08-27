class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        // ok i know tries but who cares
        string ans;
        for (int i = 0; i < 200; i++) {
            for (int j = 0; j < v.size(); j++) {
                if (j == 0) {
                    // if current length is greater than defaulting first word.
                    if (i >= v[j].size()) return ans;
                    
                    // set default 
                    ans += v[j][i];
                } else {
                    // check current char with default 
                    if (i >= v[j].size() || v[j][i] != ans[i]) {
                        ans.pop_back(); 
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};