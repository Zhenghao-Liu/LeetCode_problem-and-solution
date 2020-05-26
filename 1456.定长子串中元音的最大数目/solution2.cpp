class Solution {
    unordered_set<char> helper_set{'a','e','i','o','u'};
public:
    int maxVowels(string s, int k) {
        int count=0;
        int ans=0;
        int s_size=s.size();
        for (int i=0;i<k;++i)
            if (helper_set.find(s.at(i))!=helper_set.end())
                ++count;
        ans=count;
        for (int i=k;i<s_size;++i)
        {
            if (helper_set.find(s.at(i-k))!=helper_set.end())
                --count;
            if (helper_set.find(s.at(i))!=helper_set.end())
                ++count;
            ans=max(ans,count);
        }
        return ans;
    }
};
