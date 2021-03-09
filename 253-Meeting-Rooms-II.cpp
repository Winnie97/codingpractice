class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) { 
        vector<vector<int>> tmp;
        for (auto x:intervals)
        {
            tmp.push_back({x[0],1});
            tmp.push_back({x[1],-1});
        }
        sort(tmp.begin(),tmp.end());
        int ret=0;
        int start = 0;
        for (auto x:tmp)
        {
            if (x[1]==1)
                start++;
            else
                start--;
            ret = max(ret,start);
        }
        return ret;
    }
};