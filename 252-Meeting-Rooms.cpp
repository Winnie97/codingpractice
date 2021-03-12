class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        vector<array<int,2>> tmp;
        for (auto x:intervals)
        {
            tmp.push_back({x[0],1});
            tmp.push_back({x[1],-1});
        }
        sort(tmp.begin(),tmp.end());
        int start=0;
        for (auto x:tmp)
        {
            if (x[1]==1)
            {
                start++;
                if (start>1)
                    return false;
            }
            else
                start--;
            
        }
        return true;
    }
};