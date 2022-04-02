class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> l(26, 0);
        for (int i = 0; i < n; i++) l[s[i] - 'a'] = i;
        
        vector<int> ans;
        int prev = 0;
        int r = 0;
        for (int i = 0; i < n; i++) {
            r = max(r, l[s[i] - 'a']);
            if (i == r) {
                ans.push_back(i - prev + 1);
                prev = i + 1;
            }
        }
        return ans;
    }
};