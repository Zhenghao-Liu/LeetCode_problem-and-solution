/*
* 数据量1.5e5，那么n2做法就很危险了，又要不停查找单词是否在dictionary中，用unordered_set这个数据量也不太好
  那么就采用一个存储更优，且要方便查找单词的数据结构：字典树Trie
* 且答案返回的是最少未被识别的字符，采用dp
* dp[i]表示以从sentence[0]到sentence[i]的字符里面最少未被识别字符'
* 初始化时dp[i]=dp[i-1]+1 dp[0]=1
  最基本的情况就是dp[i]相比于dp[i-1]，加上了sentence[i]这个未识别的字母
  这样子初始化比dp[i]=i+1即最坏情况所有字符都是未识别要更加的优化
* 那么每次从0到i去遍历就是普通的暴力了，数据太大
  应该选用从i到0逆向遍历
* 那么对应的逆向遍历，即单词要是逆向的，所以存入Trie中的单词必须要逆向的存
* 设j=i;j>=0;--j 表示[j]~[i]是可能出现在dictionary中的单词
* 若发现is_left=true即遍历到一个完整的单词，那么dp[i]=min(dp[i],dp[j-1])
  因为此时是[j]~[i]是一个识别的单词，所以和dp[j-1]比较
  小心j==0情况越界，特殊处理，若[0]~[i]是一个识别单词，那么没有未识别字符，为0
* 但是不能立刻break因为有可能有多个单词的后缀是一眼的，所以要继续--j
* 当倘若发现[j]~[i]不存在与dictionary中，那么此时没有必要遍历下去了，可以直接break，
  原因就在于初始化时是dp[i]=dp[i-1]+1，若采取最坏情况初始化dp[i]=i+1，那么不仅要缩短右边界i，还要重新遍历j
* 加入小剪枝dp[i]==0，因为最小就是0所以没必要再遍历下去
*/
class Trie
{
public:
    bool is_leaf=false;
    Trie * arc[26]={NULL};
    Trie(){}
    void insert(string &s)
    {
        Trie *p=this;
        for (char &i:s)
        {
            if (p->arc[i-'a']==NULL)
                p->arc[i-'a']=new Trie;
            p=p->arc[i-'a'];
        }
        p->is_leaf=true;
    }
};
class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        if (sentence.empty())
            return 0;
        if (dictionary.empty())
            return sentence.size();
        Trie* dict=new Trie;
        for (string &i:dictionary)
        {
            reverse(i.begin(),i.end());
            dict->insert(i);
        }
        int sentence_size=sentence.size();
        vector<int> dp(sentence_size);
        for (int i=0;i<sentence_size;++i)
        {
            if (i==0)
                dp.at(i)=1;
            else
                dp.at(i)=dp.at(i-1)+1;
            Trie * p=dict;
            for (int j=i;j>=0;--j)
            {
                //小剪枝：最小就是0
                if (dp.at(i)==0)
                    break;
                int index=sentence.at(j)-'a';
                if (p->arc[index]!=NULL)
                {
                    p=p->arc[index];
                    if (p->is_leaf)
                    {
                        if (j-1>=0)
                            dp.at(i)=min(dp.at(i),dp.at(j-1));
                        else
                            dp.at(i)=0;
                    }
                }
                //else if (p->arc[index]==NULL)
                else
                {
                    break;
                }
            }
        }
        return dp.back();
    }
};
