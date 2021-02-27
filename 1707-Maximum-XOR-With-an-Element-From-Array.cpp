class Solution {
    class TrieNode {
        public:
            TrieNode* next[2];
    };
    static bool cmp(vector<int>a , vector<int> b)
    {
        return a[1]<b[1];
    }
    
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        for (int i=0; i<n; ++i)
            queries[i].push_back(i);
        sort(queries.begin(),queries.end(),cmp);
        sort(nums.begin(),nums.end());
        TrieNode* root = new TrieNode();
        int i = 0;
        vector<int> ret(n,0);
        for (auto q:queries)
        {
            
            while (i < nums.size() && nums[i]<=q[1])
            {
                TrieNode* node = root;
                for (int j=31; j>=0; --j)
                {
                    int bit = (nums[i]>>j)&1;
                    if (node->next[bit]==NULL)
                        node->next[bit] = new TrieNode();
                    node = node->next[bit];
                }
                i++;
            }
            if (i==0)
            {
                ret[q[2]]=-1;
                continue;
            }
            else
            {
                TrieNode* node = root;
				int ans = 0;
                for (int j=31; j>=0; --j)
                {
                    int bit = (q[0]>>j)&1;
                    if (node->next[1-bit]!=NULL)
                    {
                        ans = ans*2+1;
                        node = node->next[1-bit];
                    }
                    else
                    {
                        ans *= 2;
                        node = node->next[bit];
                    }
                }
                ret[q[2]] = ans;
            }
        }
        return ret;
    }
};