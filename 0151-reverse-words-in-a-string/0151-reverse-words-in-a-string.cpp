class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int l = 0, r = 0, i = 0, N = s.size();
        
        while (i < N) {
            while (i < N && s[i] != ' ') s[r++] = s[i++];
            
            if (l < r) {
                reverse(s.begin() + l, s.begin() + r);
                if (r == N) break;
                s[r++] = ' ';
                l = r;
            }
            
            ++i;
        }
        
        if (r > 0 && s[r - 1] == ' ') r--;
        s.resize(r);
        return s;
    }
};