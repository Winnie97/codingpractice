class Solution {
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if (a[0] == b[0])
            return a[1]>b[1];
        return a[0] < b[0];
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int maxRight = -1;
        for (int i=0; i<intervals.size(); ++i)
        {
            if (intervals[i][1] <= maxRight)
                count++;
            else
                maxRight = intervals[i][1];
        }
        return intervals.size()-count;
    }
};