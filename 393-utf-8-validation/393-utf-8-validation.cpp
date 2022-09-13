class Solution {
public:
    bool ifStartsWith10(string s) {
        return s.size() == 8 && (s[0] == '1' &&  s[1] == '0');
    }
    
    int countStartingOnes(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') return i;
        }
        return s.size();
    }
    
    bool validUtf8(vector<int>& v) {
        int N = v.size();
        vector<string> vs(N);
        for (int i = 0; i < N; i++) {
            bitset<8> b(v[i]);
            vs[i] = b.to_string();
        }
        
        for (int i = 0; i < N; i++) {
            int noOfZeroes = countStartingOnes(vs[i]);
            if (noOfZeroes == 0) continue;
            else if (noOfZeroes > 4 || noOfZeroes == 1) return 0;
            else {
                int cnt = noOfZeroes;
                // as we want n - 1 string that starts with "10"
                cnt--;
                i++;
                for (; i < N; i++) {
                    if (ifStartsWith10(vs[i])) cnt--;
                    else return 0;
                    if (cnt == 0) break;
                }
                if (cnt > 0) return 0;
            }
        }
        return true;
    }
};