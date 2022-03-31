class Solution {
public:
    string addStrings(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        int c = 0, n = a.length(), m = b.length();
        int i = 0;
        for (; i < max(n, m); i++) {
            int sum = c + (i < n ? a[i] : '0') + (i < m ? b[i]: '0') - 2 * '0';
            ans += ((sum % 10) + '0');
            c = sum / 10;
        }
        if (c > 0) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};