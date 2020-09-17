/*
* 先排序，这样让字典序小的单词在前面，即短的单词在前面
* 将单词放入集合中，判断当前这个单词减去最后一个字母后的新单词是否存在集合中
*/
class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> memo;
        sort(words.begin(),words.end());
        string ans;
        for (string &i:words)
        {
            if ((int)i.size()==1 || memo.find(i.substr(0,i.size()-1))!=memo.end())
            {
                if (i.size()>ans.size())
                    ans=i;
                memo.insert(i);
            }
        }
        return ans;
    }
};
