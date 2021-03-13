class Solution {
     static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(),intervals.end(),cmp);
        for (int i=0; i<intervals.size(); ++i)
        {
            count++;
            int j = i+1;
            while (j < intervals.size() && intervals[j][0] < intervals[i][1])
                j++;
            i = j-1;
        }
        return intervals.size()-count;
    }
};