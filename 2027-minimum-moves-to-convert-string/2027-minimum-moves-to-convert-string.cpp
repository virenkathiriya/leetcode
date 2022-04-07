class Solution {
public:
    int minimumMoves(string s) {
        int c = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'X') {
                c++;
                i += 2;
            }
        }
        return c;
    }
};