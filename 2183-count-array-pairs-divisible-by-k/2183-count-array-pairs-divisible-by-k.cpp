const static int MAX = 100005;
vector<int> fac[MAX];
class Solution {
public:
    
    long long countPairs(vector<int>& nums, int k) {
        vector<int> f(MAX, 0);
        if (fac[1].empty()) {
            for (int i = 1; i <= 100000; i++) {
                for (int j = i; j <= 100000; j += i) {
                    fac[j].push_back(i);
                }
            }
        }
        long long ans = 0;
        for (int &x: nums) {
            int z = k / gcd(x, k);
            // adding all nums that can be paired with x;
            ans += f[z];
            int y = gcd(x, k);
            // adding all the factors of x that are usefull for future
            for (int &i: fac[y]) f[i]++;
        }
        return ans;
    }
};