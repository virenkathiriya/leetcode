class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        int N = b.size();
        int _5 = 0, _10 = 0;
        for (int &x: b) {
            if (x == 5) _5++;
            if (x == 10) {
                _5--;
                _10++;
            }
            if (x == 20) {
                _5--;
                if (_10 == 0 && _5 >= 2) _5 -= 2;
                else _10--;
            }
            if (_5 < 0 or _10 < 0) return false;
        }
        return true;
    }
};