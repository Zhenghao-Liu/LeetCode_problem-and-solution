//先按照名字分类，之后将time转为int之后滑窗检查即可
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        set<string> ans;
        unordered_map<string,vector<int>> ump;
        int size=keyName.size();
        for (int i=0;i<size;++i)
        {
            int t=stoi(keyTime.at(i).substr(0,2))*100+stoi(keyTime.at(i).substr(3,2));
            ump[keyName.at(i)].push_back(t);
        }
        vector<int> vec;
        for (auto &i:ump)
        {
            vec=i.second;
            int vsize=vec.size();
            if (vsize<3)
                continue;
            sort(vec.begin(),vec.end());
            int k=0;
            for (int j=0;j<vsize;++j)
            {
                while (k<vsize && vec.at(k)-vec.at(j)<=100)
                    ++k;
                if (k-j>=3)
                {
                    ans.insert(i.first);
                    break;
                }
            }
        }
        return vector<string>(ans.begin(),ans.end());
    }
};
