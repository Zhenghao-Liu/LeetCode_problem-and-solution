class Solution {
    unordered_set<char> helper_set{'a','e','i','o','u'};
public:
    int maxVowels(string s, int k) {
        unordered_map<char,int> helper;
        helper.insert({'a',0});
        helper.insert({'e',0});
        helper.insert({'i',0});
        helper.insert({'o',0});
        helper.insert({'u',0});
        int ans=0;
        int s_size=s.size();
        for (int i=0;i<k;++i)
        {
            if (helper_set.find(s.at(i))!=helper_set.end())
                ++helper.at(s.at(i));
        }
        for (auto &i:helper)
            ans+=i.second;
        for (int i=k;i<s_size;++i)
        {
            if (helper_set.find(s.at(i-k))!=helper_set.end())
                --helper.at(s.at(i-k));
            if (helper_set.find(s.at(i))!=helper_set.end())
                ++helper.at(s.at(i));
            int temp=0;
            for (auto &i:helper)
                temp+=i.second;
            ans=max(ans,temp);
        }
        return ans;
    }
};
