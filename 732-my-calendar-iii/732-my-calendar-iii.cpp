class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++; mp[end]--;
        int ans = 0; int cnt = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            cnt += it -> second;
            ans = max(ans, cnt);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */