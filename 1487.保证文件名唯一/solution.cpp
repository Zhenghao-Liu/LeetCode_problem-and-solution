/*
* 不用把多个括号数字组合同时考虑，只用将最后一个括号数字组合即可
* 因为即使一个文件名他本身后面就带有括号数字组合，且当前已经存在该文件名，
  那枚举新文件名也应该是后面加上"(数字)"，而不是改变当前最后一个括号数字组合的数字
*/
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        //记录当前已经用了哪些词
        unordered_set<string> past;
        //记录当前词如果要在其后面加"(某数字)"的话，下一个数字应该填啥
        unordered_map<string,int> next;
        for (string &i:names)
        {
            if (past.find(i)==past.end())
            {
                past.insert(i);
                next[i]=1;
            }
            else
            {
                int num=next[i];
                int original_size=i.size();
                string s=i;
                while (1)
                {
                    while (s.size()>original_size)
                        s.pop_back();
                    s+='('+to_string(num)+')';
                    ++num;
                    if (past.find(s)==past.end())
                    {
                        next[i]=num;
                        next[s]=1;
                        past.insert(s);
                        i=s;
                        break;
                    }
                }
            }
        }
        return names;
    }
};
