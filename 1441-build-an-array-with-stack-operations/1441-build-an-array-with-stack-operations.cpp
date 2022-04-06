class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        vector<string> ans;
        int m = t.size();
        for (int i = 1, j = 0; j < m && i <= n; i++) {
            ans.push_back("Push");
            if (t[j] != i) ans.push_back("Pop");
            else j++;
        }
        return ans;
    }
};