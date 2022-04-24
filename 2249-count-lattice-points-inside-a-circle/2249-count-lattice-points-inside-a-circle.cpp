class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int _ = 0;
        for (int i = 0; i <= 200; i++) 
            for (int j = 0; j <= 200; j++)
                for (auto &d: circles)
                    if (abs(d[0] - i) * abs(d[0] - i) + abs(d[1] - j) * abs(d[1] - j) <= d[2] * d[2]) {
                        _++;
                        break;
                    }
        return _;
    }
};