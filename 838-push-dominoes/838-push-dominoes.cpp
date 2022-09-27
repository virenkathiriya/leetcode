class Solution {
public:
    string pushDominoes(string s) {
        int l = 0, r = 0;
        int N = s.size();
        vector<int> vp(N, 0);
        
        int f = 0, len = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == 'R') vp[i] = len = 0, f = 1;
            if (s[i] == 'L') len = f = 0;
            if (s[i] == '.' && f == 1) vp[i] = ++len;
        }
        
        f = 0, len = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (s[i] == 'L') vp[i] = len = 0, f = -1;
            if (s[i] == 'R') len = f = 0;
            if (s[i] == '.' && f == -1) vp[i] = (vp[i] != 0) ? ++len - vp[i] : -1;
        }
        
        for (int i = 0; i < N; i++) {
            int f = vp[i];
            if (f > 0 || (f == 0 && s[i] == 'R')) s[i] = 'R';
            else if (f < 0 || (f == 0 && s[i] == 'L')) s[i] = 'L';
            else s[i] = '.';
        }
        return s;
    }
};