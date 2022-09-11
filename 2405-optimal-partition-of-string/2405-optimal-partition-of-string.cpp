class Solution {
public:
    int partitionString(string s) {
        vector<int> f(26, 0);
        int ans = 0;
        string current;
        for (char &c: s) {
            int d = c - 'a';
            if (f[d]) {
                ans++;
                current = "";
                for(int i = 0; i < 26; i++) f[i] = 0;
                
            } 
            current += c;
            f[d] = 1;
        }
        if (current != "") ans++;
        return ans;
    }
};