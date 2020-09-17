/*
* 先把source整合成一个大的string，其中每行用'\n'分离
* 之后用滑窗形式找//或者/**/
* 注意某行如果去掉注释后是空的内容，那么不应该放入ans中
*/
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        ans.reserve(source.size());
        string s;
        for (string &i:source)
            s+=i+"\n";
        int size=s.size();
        string t;
        for (int i=0;i<size;++i)
        {
            if (s.at(i)=='\n')
            {
                if (t.empty() && i-2>=0 && s.at(i-2)=='*' && s.at(i-1)=='/')
                    continue;
                ans.push_back(t);
                t.clear();
                continue;
            }
            else if (s.at(i)=='/')
            {
                if (i+1<size && s.at(i+1)=='/')
                {
                    ++i;
                    for (;i+1<size;++i)
                        if (s.at(i+1)=='\n')
                            break;
                    if (t.empty())
                        ++i;
                    continue;                    
                }
                else if (i+1<size && s.at(i+1)=='*')
                {
                    i+=2;
                    for (;i<size;++i)
                        if (s.at(i)=='*' && s.at(i+1)=='/')
                        {
                            ++i;
                            break;
                        }
                    continue;
                }
            }
            t+=s.at(i);
        }
        return ans;
    }
};
