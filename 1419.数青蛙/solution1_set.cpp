class Solution {
    unordered_map<char,int> mask{{'c',0},{'r',1},{'o',2},{'a',3},{'k',4}};
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        multiset<int> helper;
        for (char &i:croakOfFrogs)
        {
            if (mask.find(i)==mask.end())
                return -1;
            int num=mask[i];
            bool judge_new=true;
            auto p=helper.find(num-1);
            if (p!=helper.end())
            {
                helper.erase(p);
                if (num==4)
                    helper.insert(-1);
                else
                    helper.insert(num);
            }
            else if (p==helper.end() && num==0)
                helper.insert(0);
            else
                return -1;
        }
        return helper.count(-1)==helper.size() ? helper.size() : -1;
    }
};
