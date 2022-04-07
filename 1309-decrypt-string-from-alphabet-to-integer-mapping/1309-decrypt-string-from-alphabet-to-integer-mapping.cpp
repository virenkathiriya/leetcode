class Solution {
public:
    string freqAlphabets(string s) {
        int r = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (i + 2 < n && isdigit(s[i + 1]) && s[i + 2] == '#') {
                s[r] = s[i] * 10 + s[i + 1] - 432;
                i += 2;
            } else {
                s[r] = s[i] + 48;
            }
            r++;
        }
        s.resize(r);
        return s;
    }
};