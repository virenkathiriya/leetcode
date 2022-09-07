class Solution {
public:
    int threeSumClosest(vector<int>& v, int t) {
        sort(v.begin(), v.end());
        int N = v.size();
        int ans = 1e8;
        for (int i = 0; i < N; i++) {
            int a = v[i];
            int l = i + 1, r = N - 1;
            while (l < r && l < N && r >= 0) {
                int b = v[l], c = v[r];
                if (abs(t - a - b - c) < abs(t - ans)) ans = a + b + c;
                
                int l1Diff = INT_MIN, r1Diff = INT_MIN;
                if (l + 1 < N && l + 1 < r) {
                    b = v[l + 1], c = v[r];
                    l1Diff = abs(t - a - b - c);
                } 
                if (r - 1 >= 0 && r - 1 > l) {
                    b = v[l], c = v[r - 1];
                    r1Diff = abs(t - a - b - c);
                }
                // you are getting lesser diff (l + 1 or r - 1) move there
                if (l1Diff < r1Diff) l++;
                else r--;
                
                if (min(l1Diff, r1Diff) > abs(t - a - b - c)) break;
            }
        }
        return ans;
    }
};
 