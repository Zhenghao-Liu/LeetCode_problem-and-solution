/*
* 要想既符合题目要求：包含所有字符c、不重叠，且字符串尽可能多，且尽可能的短
  看一眼数据量1e5，递归显然不行，那么就往贪心方面想
* 首先构建出符合条件的子串，然后按长度排序以达到尽可能的短这个要求，然后按照不重叠原则添加到ans中，
  这样为什么字符串就尽可能的多呢？因为都尽可能短了，且不重叠，当然是最优的选择
* 如何构建出包含所有字符c的字符串？
  1. 首先按照字母查找出现在s中的两头，记录在count中
  2. 因为字母出现在两头，中间可能含有别的字母，所以要想符合包含所有字符c的条件，需要进行两端拓宽，即拓宽到满足包含了所有字符c的情况
*/
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>> count(26);
        //[i][0]表length,[i][1]表begin_pos,[i][2]表end_pos，字符串在[begin_pos,end_pos]左闭右闭范围内
        //设[i][0]==INT_MAX则表示char(i+'a')没有出现在s中
        for (char i='a';i<='z';++i)
        {
            int index=i-'a';
            count.at(index).push_back(INT_MAX);
            std::size_t pos=s.find_first_of(i);
            if (pos==string::npos)
                continue;
            int first_pos=pos;
            int last_pos=s.find_last_of(i);
            count.at(index).clear();
            count.at(index)={last_pos-first_pos+1,first_pos,last_pos};
        }
        for (char i='a';i<='z';++i)
        {
            int index=i-'a';
            if (count.at(index).at(0)==INT_MAX)
                continue;
            count.at(index)=expand(s,count.at(index).at(1),count.at(index).at(2),count);
        }
        sort(count.begin(),count.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(0)<B.at(0);
        });
        vector<string> ans;
        vector<bool> use(s.size(),false);
        for (int i=0;i<26;++i)
        {
            int length=count.at(i).at(0);
            if (length==INT_MAX)
                break;
            int left=count.at(i).at(1);
            int right=count.at(i).at(2);
            bool judge_all_not_use=true;
            for (int j=left;j<=right;++j)
                if (use.at(j))
                {
                    judge_all_not_use=false;
                    break;
                }
            if (!judge_all_not_use)
                continue;
            fill(use.begin()+left,use.begin()+right+1,true);
            ans.push_back(s.substr(left,length));
        }
        return ans;
    }
    vector<int> expand(string &s,int left,int right,vector<vector<int>> &count)
    {
        for (int j=left+1;j<right;++j)
        {
            int index=s.at(j)-'a';
            int index_left=count.at(index).at(1);
            int index_right=count.at(index).at(2);
            if (left<=index_left && right>=index_right)
                continue;
            left=min(left,index_left);
            right=max(left,index_right);
            j=left;
        }
        return {right-left+1,left,right};
    }
};
