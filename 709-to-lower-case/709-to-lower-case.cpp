class Solution {
public:
    string toLowerCase(string s) {
        transform(s.begin(), s.end(), s.begin(), [&] (const char &c) { return tolower(c); });
        return s;
    }
};