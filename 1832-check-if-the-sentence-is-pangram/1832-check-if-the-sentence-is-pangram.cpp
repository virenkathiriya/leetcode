class Solution {
public:
    bool checkIfPangram(string s) {
        bool ok = true;
        vector<int> f(26, 0);
        for (char &c: s) f[c - 'a']++;
        for (int &x: f) ok &= (x > 0);
        return ok;
    }
};