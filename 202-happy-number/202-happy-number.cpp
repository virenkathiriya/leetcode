class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> seen;
        while (true) {
            int sum = 0;
            while (n) {
                int d = n % 10;
                sum += (d * d);
                n /= 10;
            }
            n = sum;
            if (seen[n]) return false;
            if (n == 1) return true;
            seen[n] = true;
        }
        return false;
    }
};