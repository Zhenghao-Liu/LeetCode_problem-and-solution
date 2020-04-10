//将acgt看做是二维的数字00 01 10 11
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int s_size=s.size();
        if (s_size<11)
            return {};
        unordered_map<char,int> mask;
        mask.insert({'A',0});
        mask.insert({'C',1});
        mask.insert({'G',2});
        mask.insert({'T',3});
        unordered_set<int> helper_set;
        int key=0;
        for (int i=0;i<10;++i)
        {
            key<<=2;
            key|=mask.at(s.at(i));
            key&=0xfffff;
        }
        helper_set.insert(key);
        unordered_set<string> ans;
        for (int i=10;i<s_size;++i)
        {
            key<<=2;
            key|=mask.at(s.at(i));
            key&=0xfffff;
            if (helper_set.find(key)!=helper_set.end())
                ans.insert(s.substr(i-9,10));
            else
                helper_set.insert(key);
        }
        return vector<string>(ans.begin(),ans.end());
    }
};
