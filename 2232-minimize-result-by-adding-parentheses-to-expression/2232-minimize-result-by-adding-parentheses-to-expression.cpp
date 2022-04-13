class Solution {
public:
    long long f(string s) {
        long long ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans = ans * 10 + (s[i] - '0');
        }
        return ans;
    }
    
    string minimizeResult(string e) {
        string num1;
        string num2;
        bool ok = false;
        for (char &c: e) {
            if (c == '+') {
                ok = true;
                continue;
            }
            if (!ok)
            num1 += c;
            else 
            num2 += c;
        }
        
        long long p = INT_MAX;
        string fans;
        int n = num1.length();
        int m = num2.length();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long curP = 1;
                string ans;
                if (i > 0) {
                    curP *= f(num1.substr(0, i));
                    ans += num1.substr(0, i);
                } 
                ans += "(";
                long long sum = 0;
                sum = f(num1.substr(i));
                ans += num1.substr(i);
                sum += f(num2.substr(0, j + 1));
                ans += "+";
                ans += num2.substr(0, j + 1);
                curP *= sum;
                ans += ")";
                if (j < m - 1) {
                    curP *= f(num2.substr(j + 1));
                    ans += num2.substr(j + 1);
                }
                
                if (curP < p) {
                    p = curP;
                    fans = ans;
                }
            }
        }
        return fans;
    }
};