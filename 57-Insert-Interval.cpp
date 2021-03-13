class Solution {
    static bool cmp(pair<int,int> x, pair<int,int> y)
    {
        if (x.first == y.first)
            return x.second > y.second;
        else
            return x.first < y.first;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<pair<int, int>> q;
        for (auto x:intervals)
        {
            q.push_back({x[0],1});
            q.push_back({x[1],-1});
        }
        q.push_back({newInterval[0], 1});
        q.push_back({newInterval[1], -1});
        sort(q.begin(), q.end(), cmp);
        int count = 0;
        vector<vector<int>> ret;
        int start, end;
        for (auto x:q)
        {
            if (x.second == 1)
            {
                count++;
                if (count==1)
                    start = x.first;
            }
            else
            {
                count--;
                if (count == 0)
                {
                    end = x.first;
                    ret.push_back({start, end});
                }
            }
        }
        return ret;
    }
};


