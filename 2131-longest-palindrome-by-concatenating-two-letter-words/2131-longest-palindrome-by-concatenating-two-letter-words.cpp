class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp;
        for (string &s: words) mp[s]++;
        
        bool single = false;
        int cnt = 0;
        for (auto &it: mp) {
            string a = it.first;
            string b = string(1, a[1]) + a[0];
            
            int m1 = mp[a], m2 = mp[b];
            if (a[0] == a[1]) {
                cnt += m1 / 2;
                single |= m1 % 2;
            } else {
                cnt += min(m1, m2);
            }
            mp[a] = mp[b] = 0;
        }
        return (cnt * 2 + single) * 2;
    }
};