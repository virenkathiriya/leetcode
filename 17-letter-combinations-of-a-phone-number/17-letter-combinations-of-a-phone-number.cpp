class Solution {
public:
    vector<string> letterCombinations(string s) {
        int n = s.length();
        if (n == 0) return {};
        vector<string> ans;
        vector<int> path;
        unordered_map<char, vector<char>> mp {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}} 
        };
        rec(mp, ans, s, "", n, 0);
        return ans;    
    }
    
    void rec(unordered_map<char, vector<char>> &mp, vector<string> &ans, string s, string cur, int &n, int ptr) {
        if (ptr == n) {
            ans.push_back(cur);
            return;
        }
        
        for (char &c: mp[s[ptr]]) {
            cur += c;
            rec(mp, ans, s, cur, n, ptr + 1);
            cur.pop_back();
        }
    }
};