/*
 * 前缀和加二分
 * 当前的i是中间区域左闭右闭的右边界
 * 先二分枚举到中间区域尽可能左的，使得中间区域小于等于右边区域的，中间区域的左边界
 * 然后二分去枚举中间区域左边界尽可能右的位置，且满足中间区域大于等于左边区域
 * 注意前缀和下的索引问题
 * 注意左中右区域都至少要有一个元素的问题
 */
typedef long long ll;
ll mod=1e9+7;
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int size=nums.size();
        vector<int> prefix;
        prefix.reserve(size+1);
        ll ans=0;
        int all_sum=0;
        for (int i=0;i<size;i++) {
            all_sum+=nums.at(i);
        }
        int cur=0;
        for (int i=0;i<size-1;i++) {
            cur+=nums.at(i);
            int right=all_sum-cur;
            prefix.push_back(cur);
            auto p=lower_bound(prefix.begin(),prefix.end(),cur-right);
            if (p!=prefix.end()) {
                p++;
                if (p==prefix.end()) {
                    continue;
                }
                int l=p-prefix.begin();
                int vp=*(p-1);
                if (vp>cur-vp) {
                    continue;
                }
                int st=l;
                int r=prefix.size()-1;
                while (l<r) {
                    int mid=l+(r-l+1)/2;
                    if (prefix.at(mid-1)<=cur-prefix.at(mid-1)) {
                        l=mid;
                    } else {
                        r=mid-1;
                    }
                }
                ans+=(ll)l-st+1;
                ans%=mod;
            }
        }
        return ans;
    }
};
