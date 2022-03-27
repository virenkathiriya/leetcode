class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& q, int l) {
        vector<long long> ans;
        for (int &x: q) {
            long long pali = 0;
            string qs = to_string(x);
            int temp = (l & 1) ? (l / 2) : (l / 2 - 1);
            pali = (long long)pow(10, temp);
            pali += x - 1;
            long long num2rev = pali;
            if (l % 2 == 1) {
                num2rev = pali / 10;
            } 
            bool ok = true;
            while (num2rev) {
                if (LONG_MAX / 10 < pali) {
                    ok = false;
                    break;
                }
                pali = pali * 10 + num2rev % 10;
                num2rev /= 10;
            }
            if (!ok) {
                ans.push_back(-1);
                continue;
            }
            string palis = to_string(pali);
            if (palis.size() > l) {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(pali);
        }
        return ans;
    }
};