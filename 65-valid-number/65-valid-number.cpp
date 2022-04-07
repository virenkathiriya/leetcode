class Solution {
public:
    bool isNumber(string s) {
        if (s.size() == 1 && !isdigit(s[0])) return false;
        int i = 0;
        if (s[i] == '+' or s[i] == '-') i++;
        
        int digit = 0, dot = 0;
        while (s[i] == '.' || isdigit(s[i])) {
            if (s[i] == '.') dot++;
            else digit++;
            i++;
        }
        
        if (digit < 1 or dot > 1) return false;
        
        if ((s[i] == 'e' or s[i] == 'E')) {
            i++;
            if (s[i] == '+' or s[i] == '-') i++;
            
            int dcnt = 0;
            while (isdigit(s[i])) dcnt++, i++;
            cout << dcnt;
            if (dcnt == 0) return false;
        } 
        return (i == s.length());
    }
};