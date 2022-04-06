class Solution {
public:
    string defangIPaddr(string a) {
        string ans;
        for (char &c: a) {
            if (c == '.') ans += "[.]";
            else ans += c;
        }
        return ans;
    }
};