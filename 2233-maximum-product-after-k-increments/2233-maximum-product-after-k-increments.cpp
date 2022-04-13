class Solution {
public:
    int maximumProduct(vector<int>& v, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        for (int &x: v) pq.push(x);
        while (k--) {
            int t = pq.top();
            pq.pop();
            pq.push(++t);
        }
        long long ans = 1;
        while (!pq.empty()) {
            ans = (ans * pq.top() * 1LL) % 1000000007;
            pq.pop();
        }
        return ans;
    }
};