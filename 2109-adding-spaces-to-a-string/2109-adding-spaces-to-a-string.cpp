class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int n = spaces.size();
        ans += s.substr(0, spaces[0] - 0);
        for(int i = 0; i < n; i++) {
            ans += " " + s.substr(spaces[i], ((i + 1 < n) ? spaces[i + 1]: s.length()) - spaces[i]);
        }
        return ans;
    }
};