class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (s[0] == '0') return 0;
        int i2 = 1, i1 = 1;
        for (int i = 1; i < n; i++) {
            int ans = 0;
            if (s[i] == '0' && (s[i - 1] != '1' and s[i - 1] != '2')) return 0;
            if (s[i] != '0') ans = i1;
            int x = stoi(s.substr(i - 1, 2));
            if (x > 9 && x <= 26) ans += i2;
            swap(i1, i2);
            i1 = ans;
        }
        return i1;
    }
};