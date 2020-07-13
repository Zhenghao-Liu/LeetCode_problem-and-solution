//其实就是求d里面的单词，是s的子集，且尽可能的长，相同长下字典序最小，那么预处理加判断子集即可
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end(),[](const string &A,const string &B){
            return A.size()==B.size() ? A<B : A.size()>B.size();
        });
        for (string &i:d)
            if (is_sub(i,s))
                return i;
        return "";
    }
    bool is_sub(string & sub,string & comp)
    {
        int i=0,j=0;
        int sub_size=sub.size(),comp_size=comp.size();
        for (;i<sub_size && j<comp_size;++j)
            if (sub.at(i)==comp.at(j))
                ++i;
        return i==sub_size;
    }
};
