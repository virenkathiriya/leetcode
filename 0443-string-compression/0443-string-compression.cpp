class Solution {
public:
    int compress(vector<char>& s) {
        int ans = 0, N = s.size(), w = 0;
        
        for (int i = 0; i < N; i++) {
            int cnt = 1;
            
            ans++, s[w++] = s[i];
            
            while (i + 1 < N && s[i] == s[i + 1]) cnt++, i++;
            
            if (cnt == 1) continue;
            
            string scnt = to_string(cnt);
            for (char &c: scnt) s[w++] = c;
            ans += scnt.size();
        }
        return ans;
    }
};