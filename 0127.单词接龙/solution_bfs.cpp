/**
* word_id表单词word对于序号id的映射
* id_word表序号id对于单词word的映射
* 方便则将beginWord设为序号为0
* edges表示每个单词之间倘若可以互相转换，则建立一个双向边
* cost[i]表示beginWord转换成单词id_word[i]所需要的步数
* 既然求最短，就采用bfs
* 采用队列存储当前可能路径上的完整序列，即queue存的是id
  倘若遍历到了endWord再通过cost[i]即可
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
                unordered_map<string,int> word_id;
        vector<string> id_word;
        //建立单词和序号的互索引
        id_word.push_back(beginWord);
        word_id[beginWord]=0;
        for (string &i:wordList)
        {
            word_id[i]=id_word.size();
            id_word.push_back(i);
        }
        if (word_id.find(endWord)==word_id.end())
            return {};
        int size=id_word.size();
        //建立双向边
        vector<vector<int>> edges(size);
        for (int i=0;i<size;++i)
            for (int j=i+1;j<size;++j)
                if (can_transfrom(id_word.at(i),id_word.at(j)))
                {
                    edges.at(i).push_back(j);
                    edges.at(j).push_back(i);
                }
        //从beginWord转换成别的单词的代价
        vector<int> cost(size,INT_MAX/2);
        cost.at(0)=1;
        //bfs
        queue<int> helper;
        helper.push({0});
        while (!helper.empty())
        {
            int cur=helper.front();
            helper.pop();
            for (int &next:edges.at(cur))
            {
                if (cost.at(next)>=cost.at(cur)+1)
                {
                    cost.at(next)=cost.at(cur)+1;
                    if (next==word_id.at(endWord))
                        return cost.at(next);
                    helper.push(next);
                }
            }
        }
        return 0;
    }
    bool can_transfrom(const string &a,const string &b)
    {
        int diff=0;
        int length=a.size();
        for (int i=0;i<length && diff<=1;++i)
            if (a.at(i)!=b.at(i))
                ++diff;
        return diff==1;
    }
};
