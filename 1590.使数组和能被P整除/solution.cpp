/*
* 设nums的数组元素总和是sum，要删除的区间元素总和是delete_sum
  即(sum-delete_sum)%p==0
* 那么借用同余定理，这样不用考虑sum-delete_num==kp的系数k的问题
  即(a-b)%p==(a%p-b%p+p)%p
* 优化成(sum%p-delete_sum%p+p)%p==0
  这里sum%p在求sum的时候直接sum%=p即可，下面就直接用sum代替sum%p
  这也就保证了括号内的运算结果就是0
  即(sum-delete_sum%p+p)%p==0
* 要找一个区间和是一个固定值delete_sum，就想起了永远的神twosum
*/
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum=0;
        for (int i:nums)
        {
            sum+=i;
            sum%=p;
        }
        if (sum==0 || p==1)
            return 0;
        //key是前缀和，value是对应的位置
        unordered_map<int,int> pos;
        pos[0]=-1;
        int prefix=0;
        int size=nums.size();
        int ans=INT_MAX;
        for (int i=0;i<size;++i)
        {
            prefix+=nums.at(i);
            prefix%=p;
            //(prefix%p-tar%p+p)%p==delete_sum%p
            //(sum-delete_sum%p+p)%p==0
            int tar=(prefix-sum+p)%p;
            if (pos.find(tar)!=pos.end())
                ans=min(ans,i-pos.at(tar));
            pos[prefix]=i;
        }
        return (ans==INT_MAX || ans==size) ? -1 : ans;
    }
};
