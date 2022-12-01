class Solution {
public:
    vector<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    
    bool f(char c) {
        return find(v.begin(), v.end(), c) != v.end();    
    }
    
    bool halvesAreAlike(string s) {
        int N = s.size();
        int cnt = 0;
        for (int i = 0; i < N / 2; i++) cnt += f(s[i]);
        for (int i = N / 2; i < N; i++) cnt -= f(s[i]);
        return cnt == 0;
    }
};