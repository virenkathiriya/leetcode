class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26, 0), f2(26, 0);
        int N = s2.size(), M = s1.size();
        if (N < M) return false;
        for (int i = 0; i < M; ++i) {f1[s1[i] - 'a']++, f2[s2[i] - 'a']++;}
        
        int cnt = 0;
        for (int i = 0; i < 26; i++) cnt += (f1[i] == f2[i]);
        
        for (int i = 0; i + M < N; i++) {
            int r = s2[i + M] - 'a';
            int l = s2[i] - 'a';
            
            if (cnt == 26) return true;
            f2[r]++;
            if (f2[r] == f1[r]) cnt++;
            else if (f2[r] == f1[r] + 1) cnt--;
            f2[l]--;
            if (f2[l] == f1[l]) cnt++;
            else if (f2[l] == f1[l] - 1) cnt--;
        }
        return cnt == 26;
    }
};