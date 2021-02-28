class Solution {
    static bool cmp(string a, string b)
    {
        return a.size()<b.size();
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        unordered_map<string, int> Map;
        unordered_set<string>Set;
        int n = words.size();
        for (int i=0; i<n; ++i)
            Map[words[i]] = i;
        sort(words.begin(), words.end(), cmp);
        vector<vector<int>> ret;
        for (int i=0; i<n; ++i)
        {
            string word = words[i];
            for (int j=0; j<=word.size(); ++j)
            {
            
                if (isPalindrome(word, 0, j-1))
                {
                    string w2 = word.substr(j);
                    reverse(w2.begin(), w2.end());
                    if (Set.find(w2)!=Set.end())
                        ret.push_back({Map[w2], Map[word]});
                }
                if (isPalindrome(word, j, w.size()-1))
                {
                    string w2 = word.substr(0,j);
                    reverse(w2.begin(), w2.end());
                    if (Set.find(w2)!=Set.end())
                        ret.push_back({Map[word], Map[w2]});
                }
            }
            Set.insert(word);
        }
        return ret;
    }
    bool isPalindrome(string w, int i, int j)
    {
        while (i < j)
        {
            if (w[i]!=w[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};