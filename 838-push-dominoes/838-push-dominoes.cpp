class Solution {
public:
    string pushDominoes(string s) {
        int l = 0, r = 0;
        int N = s.size();
        vector<int> vp(N, 0);
        
        int f = 0, len = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == 'R') {
                vp[i] = 0;
                len = 0;
                f = 1;
            }
            if (s[i] == 'L') {
                len = 0;
                f = 0;
            }
            
            if (s[i] == '.') {
                if (f == 1) {
                    len++;
                    vp[i] = len;
                }
            }
        }
        
        f = 0, len = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (s[i] == 'L') {
                vp[i] = 0;
                len = 0;
                f = -1;
            }
            
            if (s[i] == 'R') {
                len = 0;
                f = 0;
            }
            
            if (s[i] == '.') {
                if (f == -1) {
                    len++;
                    if (vp[i] != 0) {
                        if (vp[i] == len) {
                            vp[i] = 0;
                        } else if (vp[i] > len) {
                            vp[i] = -len;
                        }
                    } else {
                        vp[i] = -1;
                    }
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            int c = vp[i];
            if (c > 0 || (c == 0 && s[i] == 'R')) s[i] = 'R';
            else if (c < 0 || (c == 0 && s[i] == 'L')) s[i] = 'L';
            else s[i] = '.';
        }
        return s;
    }
};