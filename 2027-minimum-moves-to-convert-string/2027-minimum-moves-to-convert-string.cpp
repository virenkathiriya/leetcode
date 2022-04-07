class Solution {
public:
    int minimumMoves(string s) {
        int c = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'X') {
                c++;
                i += 2;
            }
        }
        return c;
    }
};