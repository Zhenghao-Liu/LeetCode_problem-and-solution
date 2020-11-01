//暴力，n^2*logn
const int MAXN=500;
int cur[MAXN];
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size();
        int m=l.size();
        vector<bool> ans(m,false);
        for (int i=0;i<m;++i)
        {
            int ll=l.at(i),rr=r.at(i);
            int size=rr-ll+1;
            for (int j=0;j<size;++j)
            {
                cur[j]=nums.at(ll);
                ++ll;
            }
            sort(cur,cur+size);
            int j=1;
            int d=cur[1]-cur[0];
            for (;j<size;++j)
                if (cur[j]-cur[j-1]!=d)
                    break;
            if (j==size)
                ans.at(i)=true;
        }
        return ans;
    }
};
