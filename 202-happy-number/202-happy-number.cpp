class Solution {
public:
    long long f(long long n) {
        long long sum = 0;
        while (n > 0) {
            int x = n % 10;
            sum += x * x;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        map<long long, bool> mp;
        long long ans = f(n);
        while (!mp[ans] && ans != 1) {
            mp[ans] = true;
            ans = f(ans);
        }
        return ans == 1;
    }
};