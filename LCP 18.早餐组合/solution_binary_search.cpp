//当前s中元素i，要查找i+j<=x的j有多少个，就是找j<=x-i的元素有多少个，所以直接排序然后二分即可
//upper_bound找到的是>x-i的第一个元素的位置，其实就是j<=x-i区间迭代器的end
class Solution {
    int mod=1e9+7;
public:
    int breakfastNumber(vector<int>& s, vector<int>& d, int x) {
        sort(d.begin(),d.end());
        int ans=0;
        for (int i:s)
        {
            int p=upper_bound(d.begin(),d.end(),x-i)-d.begin();
            ans+=p;
            ans%=mod;
        }
        return ans;
    }
};
