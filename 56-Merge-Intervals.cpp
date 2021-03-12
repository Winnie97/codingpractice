class Solution {
    static bool cmp(pair<int,int> x, pair<int,int> y)
    {
        if (x.first == y.first)
            return x.second > y.second;
        else
            return x.first < y.first;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> tmp;
        for (auto x:intervals)
        {
            tmp.push_back({x[0],1});
            tmp.push_back({x[1],-1});
        }
        sort(tmp.begin(),tmp.end(),cmp);
        vector<vector<int>> ret;
        int count = 0;
        int start,end;
        for (auto x:tmp)
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
                    ret.push_back({start,end});
                }
            }
        }
        return ret;
    }
};