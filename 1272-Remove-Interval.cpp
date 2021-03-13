class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int R = toBeRemoved[1];
        int L = toBeRemoved[0];
        vector<vector<int>> ret;
        for (auto x:intervals)
        {
            if (x[1] <= L || x[0] >= R)
                ret.push_back({x[0],x[1]});
            else 
            {
                if (x[0] < L)
                    ret.push_back({x[0],L});
                if (x[1] > R)
                    ret.push_back({R,x[1]});
            }
        }
        return ret;
    }
};