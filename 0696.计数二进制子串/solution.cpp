/*
* 滑窗方式统计连续的0、1有多少个
* eg:0011100
  就是2,3,2
* 只关心连续（相邻）的，且是0/1相同数量
* 所以就是min(i,i-1)
*/
class Solution {
public:
    int countBinarySubstrings(string s) {
        int s_size=s.size();
        int ans=0;
        int prev=0;
        for (int i=0;i<s_size;)
        {
            int j;
            for (j=i;j<s_size;++j)
                if (s.at(j)!=s.at(i))
                    break;
            ans+=min(j-i,prev);
            prev=j-i;
            i=j;
        }
        return ans;
    }
};
