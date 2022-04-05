class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int a = -1, b = -1;
        int n = s1.length();
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                if (b != -1) return false;
                if (a != -1) {
                    b = i;
                } else {
                    a = i;
                }
            }
        }
        if (a == -1 && b == -1) return true;
        if (a == -1 ^ b == -1) return false;
        return s1[a] == s2[b] && s1[b] == s2[a];
    }
};