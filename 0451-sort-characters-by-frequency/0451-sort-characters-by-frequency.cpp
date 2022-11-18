class Solution {
public:
    string frequencySort(string s) {
        vector<int> f(128, 0);
        for (char &c: s) f[c]++;
        sort(s.begin(), s.end(), [&](char &a, char &b) { return (f[a] == f[b]) ? (a > b) : (f[a] > f[b]); });
        return s;
    }
};