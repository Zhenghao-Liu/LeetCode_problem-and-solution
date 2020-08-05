//直接哈希表存索引
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int list1_size=list1.size();
        int list2_size=list2.size();
        int count=INT_MAX;
        unordered_map<string,int> dict;
        for (int i=0;i<list1_size;++i)
            dict.insert({list1.at(i),i});
        for (int i=0;i<list2_size;++i)
        {
            if (dict.find(list2.at(i))!=dict.end())
            {
                int index=dict.at(list2.at(i));
                if (index+i<count)
                {
                    count=index+i;
                    ans.clear();
                    ans.push_back(list2.at(i));
                }
                else if (index+i==count)
                {
                    ans.push_back(list2.at(i));
                }
            }
        }
        return ans;
    }
};
