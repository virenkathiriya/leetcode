class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int noOfTries = minutesToTest / minutesToDie + 1;
        int ans = 0;
        while (pow(noOfTries, ans) < buckets) ans++;
        return ans;
    }
};