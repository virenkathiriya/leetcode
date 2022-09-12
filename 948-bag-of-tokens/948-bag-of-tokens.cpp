class Solution {
public:
    int bagOfTokensScore(vector<int>& v, int power) {
        int score = 0;
        int N = v.size();
        sort(v.begin(), v.end());
        int l = 0, r = N - 1;
        // initial power ❤️
        int lastOperation = 0;
        // initial gain
        while (l < N && power - v[l] >= 0) {
            cout << v[l] << " score++\n";
            power -= v[l];
            l++;
            score++;
        }
        int lastIndexOfPowerAddition = N;
        while (l < r) {
            while (l < N && power - v[l] >= 0) {
                cout << v[l] << " score++\n";
                power -= v[l];
                l++;
                score++;
            }
            if (l < r && r >= 0) {
                if (score <= 0) return score;
                cout << v[r] << " score--\n";
                power += v[r];
                lastIndexOfPowerAddition = r;
                score--;
                r--;
            }
        }
        r = lastIndexOfPowerAddition;
        while (r < N && power >= v[r]) {
            if (r >= 0) {
                cout << v[r] << " back score++\n";
                power -= v[r];
                score++;
            }
            r++;
        }
        cout << "\n";
        return score;
    }
};