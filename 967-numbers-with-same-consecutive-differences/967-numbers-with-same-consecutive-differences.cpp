class Solution {
public:
    void calc(int num, int k, vector<vector<vector<int>>>& lk, vector<int> &ans, int length, int n) {
        if (length > n) return;
        int d = num % 10;
        for (int &x: lk[d][k]) {
            if (length + 1 > n) continue;
            
            int newNum = num * 10 + x;
            if (length + 1 == n)
            ans.push_back(newNum);
            calc(newNum, k, lk, ans, length + 1, n);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<vector<vector<int>>> lk(10, vector<vector<int>>(10, vector<int>()));
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                for (int j = 0; j < 10; j++) {
                    if (abs(i - j) == k) {
                        lk[i][k].push_back(j);
                    }
                }
            }
        }
        vector<int> ans;
        for (int i = 1; i < 10; i++)
            calc(i, k, lk, ans, 1, n);
        return ans;
    }
};