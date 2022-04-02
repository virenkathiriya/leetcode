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
        if (ans[0] == '0') return "0";
        return ans;
    }
    
    string multiply(string num1, string num2) {
        if (num1.size() == 1 && num2.size() == 1) {
            int a = num1[0] - '0';
            int b = num2[0] - '0';
            int c = a * b;
            return to_string(c);
        }
        if (num1.size() > num2.size()) swap(num1, num2);
        string ans = "0";
        int n = num2.size();
        for (int i = 0; i < n; i++) {
            ans = addStrings(ans, multiply(num1, string(1, num2[i])) + string(n - i - 1, '0'));
        }
        return ans;
    }
};