class Solution {
public:
    bool backspaceCompare(string s, string t) {
        bool ok = true;
        int i = s.length(), j = t.length();
        int sc = 0, tc = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#')
                sc++, i--;
                else if (sc > 0)
                sc--, i--;
                else
                break;
            }
            while (j >= 0) {
                if (t[j] == '#')
                tc++, j--;
                else if (tc > 0)
                tc--, j--;
                else
                break;
            }
            if (i < 0 && j < 0) break;
            
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) return false;
                i--; j--;
            } else {
                return false;
            }
        }
        return true;
    }
};