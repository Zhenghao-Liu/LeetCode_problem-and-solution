//保留重复字母成成本最大的那个
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans=0;
        int size=s.size();
        for (int i=0;i<size;)
        {
            int j=i+1;
            for (;j<size;++j)
                if (s.at(j)!=s.at(i))
                    break;
            if (j==i+1)
            {
                i=j;
                continue;
            }
            int s=i,e=j-1;
            int maxv=INT_MIN;
            int p=-1;
            for (int k=s;k<=e;++k)
                if (cost.at(k)>maxv)
                {
                    maxv=cost.at(k);
                    p=k;
                }
            for (int k=s;k<=e;++k)
                if (k!=p)
                    ans+=cost.at(k);
            i=j;
        }
        return ans;
    }
};
