class Solution {
public:
    bool isP(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        return r == s;
    }
    
    bool isStrictlyPalindromic(int n) {
        bool ok = true;
        for (int i = 2; i <= n - 2; i++) {
            string s;
            int m = n;
            while (m > 0) {
                int d = m % i;
                s += to_string(d);
                m /= i;
            }
            
            ok &= isP(s);
            if (!ok) return ok;
        }
        return ok;
    }
};