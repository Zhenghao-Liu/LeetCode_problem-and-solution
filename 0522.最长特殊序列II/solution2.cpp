//判断一个strs[i]是否不是其他所有strs[j]的子串
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
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
                ans=max(ans,(int)strs.at(i).size());
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
