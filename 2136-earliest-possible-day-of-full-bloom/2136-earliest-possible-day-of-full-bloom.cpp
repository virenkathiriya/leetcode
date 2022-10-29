class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int N = plantTime.size();
        vector<int> ind(N);
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&](int i, int j) {
            return growTime[i] > growTime[j]; 
        });
        int ans = 0;
        int t = 0;
        for (int &x: ind) {
            t += plantTime[x];
            ans = max(ans, t + growTime[x]);
        }
        return ans;
    }
};