class Solution {
public:
    int halveArray(vector<int>& v) {
        double sum = 0;
        priority_queue<double> pq;
        for (int &i: v) {sum += i; pq.push(i);}
        int cnt = 0;
        double target = sum / 2;
        while (sum > target) {
            double x = pq.top();
            pq.pop();
            sum -= x / 2;
            pq.push(x / 2);
            cnt++;
        }
        return cnt;
    }
};