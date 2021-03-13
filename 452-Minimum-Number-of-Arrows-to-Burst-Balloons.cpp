class Solution {
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1]<b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 0;
        sort(points.begin(),points.end(),cmp);
        for (int i=0; i<points.size(); ++i)
        {
            count++;
            int j = i+1;
            while (j < points.size() && points[j][0] <= points[i][1])
                j++;
            i = j-1;
        }
        return count;
    }
};