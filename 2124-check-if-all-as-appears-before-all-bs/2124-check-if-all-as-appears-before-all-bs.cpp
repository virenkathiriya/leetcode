class Solution {
public:
    bool checkString(string s) {
        bool ok = true;
        for (char &c: s) {
            if (c == 'b' && ok) ok = false;
            else if (!ok && c == 'a') return false;
        }
        return true;
    }
};