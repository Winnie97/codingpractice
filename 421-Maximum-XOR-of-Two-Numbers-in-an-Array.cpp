class Solution {
    class TrieNode
    {
        public:
            TrieNode* next[2];
            TrieNode()
            {
                next[0]=NULL;
                next[1]=NULL;
            }
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for (int x : nums)
        {
            TrieNode* node = root;
            for (int j=31; j>=0; --j)
            {
                int k = ((x>>j)&1);
                if (node->next[k]==NULL)
                    node->next[k] = new TrieNode();
                node = node->next[k];
            }
        }
        int ret = 0;
        
        for (int x:nums)
        {
            TrieNode* node = root;
			int ans = 0;
            for (int j=31; j>=0; --j)
            {
                int bit = ((x>>j)&1);
                if (node->next[1-bit] != NULL)
                {
                    ans = 2*ans+1;
                    node = node->next[1-bit];
                }
                else
                {
                    ans *= 2;
                    node = node->next[bit];
                }
            }
            ret = max(ret, ans);
        }
        return ret;
    }
};