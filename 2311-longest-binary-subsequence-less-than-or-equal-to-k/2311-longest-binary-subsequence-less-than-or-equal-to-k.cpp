class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int ans = 0;
        int j = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (ans < 32 && bitset<64>(s.substr(i)).to_ulong() <= k) {
                ans++;
            } 
            else if (s[i] == '0') ans++;
        }
        
        return ans;
    }
};