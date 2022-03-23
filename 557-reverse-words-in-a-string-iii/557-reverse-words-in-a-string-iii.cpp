class Solution {
public:
    void rev(string &s, int st, int len) {
        for(int i = st; i < st + (len) / 2; i++) {
            swap(s[i], s[2 * st + len - i - 1]);
        }
    }
    string reverseWords(string s) {
        int len = 0;
        int st = 0;
        int N = s.size();
        for(int i = 0; i < N; i++) {
            if (s[i] == ' ') {
                if (len == 0) continue;
                else {
                    rev(s, st, len);
                    len = 0;
                }
            } else {
                if(len == 0) {
                    st = i;
                }
                len++;
            }
        }
        if (len) {
            rev(s, st, len);
        }
        return s;
    }
};