class Solution {
public:
    int lengthOfLastWord(string s) {
        string word;
        int N = s.length();
        bool ok = false;
        for(int i = N - 1; i >= 0; i--) {
            if(s[i] == ' ' && !ok) {
                continue;
            }
            ok = true;
            if(s[i] == ' ') {
                return word.length();
            } else {
                word += s[i];
            }
        }
        return word.length();
    }
};