/*
 * 最多只有16条边，可以用状压去枚举
 * 用vec表示每栋楼出去的人和进来的人，若都为0，则表示可以满足，之后统计该状态有几个1即是满足的数目
 */
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int size=requests.size();
        int ALL=(1<<size)-1;
        vector<int> vec(n);
        int ans=0;
        for (int i=1;i<=ALL;++i)
        {
            fill(vec.begin(),vec.end(),0);
            int ii=i;
            int index=0;
            int cnt=0;
            while (ii!=0)
            {
                if ((ii&1)!=0)
                {
                    ++vec.at(requests.at(index).at(1));
                    --vec.at(requests.at(index).at(0));
                    ++cnt;
                }
                ++index;
                ii>>=1;
            }
            int j;
            for (j=0;j<n;++j)
                if (vec.at(j)!=0)
                    break;
            if (j==n)
                ans=max(ans,cnt);
        }
        return ans;
    }
};
