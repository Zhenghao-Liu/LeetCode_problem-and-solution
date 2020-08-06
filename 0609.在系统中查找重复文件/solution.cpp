//按照文件的内容作为key，然后注意重复文件至少包括两个相同内容文件
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,int> dict;
        vector<vector<string>> res;
        string pos;
        string file;
        string content;
        for (string &i:paths)
        {
            int size=i.size();
            pos.clear();
            int j;
            for (j=0;j<size && i.at(j)!=' ';++j)
                pos+=i.at(j);
            pos+="/";
            for (++j;j<size;++j)
            {
                file.clear();
                while (i.at(j)!='(')
                {
                    file+=i.at(j);
                    ++j;
                }
                ++j;
                content.clear();
                while (i.at(j)!=')')
                {
                    content+=i.at(j);
                    ++j;
                }
                ++j;
                if (dict.find(content)!=dict.end())
                {
                    res.at(dict.at(content)).push_back(pos+file);
                }
                else
                {
                    int index=dict.size();
                    dict.insert({content,index});
                    res.push_back({});
                    res.at(index).push_back(pos+file);
                }
            }
        }
        vector<vector<string>> ans;
        for (vector<string> &i:res)
            if ((int)i.size()>1)
                ans.push_back(i);
        return ans;
    }
};
