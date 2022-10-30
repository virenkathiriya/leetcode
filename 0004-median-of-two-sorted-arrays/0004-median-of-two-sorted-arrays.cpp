class Solution {
public:
    double f(vector<int> &a, vector<int> &b) {
        int n1 = a.size(), n2 = b.size();
        int t = (n1 + n2) / 2;
        int l = 0, r = n1;
        while (l <= r) {
            int m1 = l + (r - l) / 2;
            int m2 = t - m1;
            
            int l1 = (m1 == 0) ? INT_MIN: a[m1 - 1];
            int l2 = (m2 == 0) ? INT_MIN: b[m2 - 1];
            
            int r1 = (m1 == n1) ? INT_MAX: a[m1];
            int r2 = (m2 == n2) ? INT_MAX: b[m2];
            
            if (l1 > r2) {
                r = m1 - 1;
            } else if (l2 > r1) {
                l = m1 + 1;
            } else {
                return ((n1 + n2) % 2) ? min(r1, r2) : ((max(l1, l2) + min(r1, r2)) / 2.0);
            }
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size(), n2 = b.size();
        return (n1 > n2) ? f(b, a): f(a, b);
    }
};