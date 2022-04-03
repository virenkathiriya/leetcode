class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int n = v.size();
        if (n == 1) return;
        // finding breakpoint
        int b = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] < v[i + 1]) {
                b = i;
                break;
            }
        }
        if (b == -1) {
            reverse(v.begin(), v.end());
            return;
        }
        
        // finding next larger element 
        int l = -1;
        for (int i = n - 1; i > b; i--) {
            if (v[i] > v[b]) {
                l = i;
                break;
            }
        }
        
        swap(v[l], v[b]);
        sort(v.begin() + b + 1, v.end());
    }
};