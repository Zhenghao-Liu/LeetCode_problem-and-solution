//显然长度更长的更可能是最长特殊序列，则从长度更长的串开始检测
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),[](const string &A,const string &B){
            return A.size()>B.size();
        });
        int ans=-1;
        int strs_size=strs.size();
        for (int i=0;i<strs_size;++i)
        {
            int j;
            for (j=0;j<strs_size;++j)
            {
                if (j==i)
                    continue;
                if (is_sub(strs.at(i),strs.at(j)))
                    break;
            }
            if (j==strs_size)
                return (int)strs.at(i).size();
        }
        return ans;
    }
    bool is_sub(string &A,string &B)
    {
        int A_size=A.size(),B_size=B.size();
        int i=0,j=0;
        for (;i<A_size && j<B_size;++j)
            if (A.at(i)==B.at(j))
                ++i;
        return i==A_size;
    }
};
