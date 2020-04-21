//用list来减少每次查找的次数
class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        int increase_size=increase.size();
        int requirements_size=requirements.size();
        vector<int> ans(requirements_size,-1);
        list<vector<int>> mask;
        for (int i=0;i<requirements_size;++i)
        {
            requirements[i].push_back(i);
            mask.push_back(requirements[i]);
        }
        mask.sort();
        int C=0,R=0,H=0;
        for (auto i=mask.begin();i!=mask.end();)
        {
            if (C>=(*i)[0] && R>=(*i)[1] && H>=(*i)[2])
            {
                ans.at((*i)[3])=0;
                mask.erase(i++);
            }
            else if (C<(*i)[0] && R<(*i)[1] && H<(*i)[2])
                break;
            else
                ++i;
        }
        for (int i=0;i<increase_size;++i)
        {
            C+=increase[i][0];
            R+=increase[i][1];
            H+=increase[i][2];
            for (auto j=mask.begin();j!=mask.end();)
            {
                if (C>=(*j)[0] && R>=(*j)[1] && H>=(*j)[2])
                {
                    ans.at((*j)[3])=i+1;
                    mask.erase(j++);
                }
                else if (C<(*j)[0] && R<(*j)[1] && H<(*j)[2])
                    break;
                else
                    ++j;
            }
            if (mask.empty())
                return ans;
        }
        return ans;
    }
};
