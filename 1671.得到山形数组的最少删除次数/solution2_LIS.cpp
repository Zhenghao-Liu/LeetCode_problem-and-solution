/*
 * 求LIS最长上升子序列的长度，包括当前[i]
 * 最后删除则是 总长size-（左侧上升子序列长度+右侧上升序列长度-1）
 * 注意山顶左右两侧都至少要有一个元素
 */
const int MAXN=1000;
int l2r[MAXN];
int r2l[MAXN];
const int INF=0x3f3f3f3f;
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int size=nums.size();
        memset(l2r,0x3f,sizeof(l2r));
        memset(r2l,0x3f,sizeof(r2l));
        vector<int> vec;
        vec.reserve(size);
        for (int i=0;i<size;++i)
        {
            int cur=nums.at(i);
            auto pos=lower_bound(vec.begin(),vec.end(),cur);
            if (pos==vec.end())
                vec.push_back(cur);
            else
                *pos=cur;
            l2r[i]=vec.size();
        }
        vec.clear();
        for (int i=size-1;i>=0;--i)
        {
            int cur=nums.at(i);
            auto pos=lower_bound(vec.begin(),vec.end(),cur);
            if (pos==vec.end())
                vec.push_back(cur);
            else
                *pos=cur;
            r2l[i]=vec.size();
        }
        int ans=INF;
        for (int i=1;i<size-1;++i)
        {
            int l=l2r[i];
            int r=r2l[i];
            if (l>1 && r>1)
                ans=min(ans,size-(l+r-1));
        }
        return ans;
    }
};
