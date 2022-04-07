class Solution {
public:
    string largestMultipleOfThree(vector<int>& d) {
        string s;
        sort(d.begin(), d.end(), greater<>());
        int cnt2 = 0, cnt1 = 0;
        for (int &x: d) {
            if (x % 3 == 0) s += (x + '0');
            else if (x % 3 == 1) cnt1++;
            else cnt2++;
        }
        int c1 = cnt1 % 3;
        int c2 = cnt2 % 3;
        if (c1 == 0 && cnt1 > 0 && c2 == 2) cnt1--;
        else if (c2 == 0 && cnt2 > 0 && c1 == 2) cnt2--;
        else {
            cnt2 -= max(0, c2 - c1);
            cnt1 -= max(0, c1 - c2);
        }
        
        for (int &x: d) {
            if (cnt1 && x % 3 == 1) {
                s += (x + '0');
                cnt1--;
            } else if (cnt2 && x % 3 == 2) {
                s += (x + '0');
                cnt2--;
            } 
        }
        sort(s.begin(), s.end(), greater<>());
        reverse(s.begin(), s.end());
        while (s.size() > 1 && s.back() == '0') s.pop_back();
        reverse(s.begin(), s.end());
        return s;
    }
};