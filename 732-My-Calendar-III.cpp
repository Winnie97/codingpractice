class MyCalendarThree {
    multiset<array<int,2>> Set;
public:
    MyCalendarThree() {

    }
    
    int book(int start, int end) {
        Set.insert({start,1});
        Set.insert({end,-1});
        int count = 0;
        int k = 0;
        for (auto x:Set)
        {
            count += x[1];
            k = max(count,k);
        }
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */