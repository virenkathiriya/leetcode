class Solution {
public:
    string pushDominoes(string s) {
        int l = 0, r = 0;
        int N = s.size();
        vector<pair<int, int>> vp(N, {0, 0});
        
        int f = 0, len = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == 'R') {
                vp[i] = {1, 0};
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
                    vp[i] = {f, len};
                }
            }
        }
        f = 0, len = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (s[i] == 'L') {
                vp[i] = {-1, 0};
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
                    if (vp[i].first != 0) {
                        if (vp[i].second == len) {
                            vp[i] = {0, 0};
                        } else if (vp[i].second > len) {
                            vp[i] = {-1, len};
                        }
                    } else {
                        vp[i] = {-1, len};
                    }
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            int c = vp[i].first;
            if (c == 0) s[i] = '.';
            else if (c == 1) s[i] = 'R';
            else s[i] = 'L';
        }
        return s;
    }
};