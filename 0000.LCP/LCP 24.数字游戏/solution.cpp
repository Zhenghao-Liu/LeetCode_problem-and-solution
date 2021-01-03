/*
* nums[a]+1==nums[a+1]
  变换下就是nums[a]-a==nums[a+1]-(a+1)
  即变换题意：使nums[i]-i后的数组，变成全部元素相等最少需要步数
* 那么变成全部元素相等就是往中位数去变
  证明看lc462.最少移动次数使数组元素相等II
* 但是462题是静态数组，本题是类似于数据流的形式
  所以求中位数想到了lc295.寻找数据流的中位数
* 但是求步数呢，每个元素去减或加求得中位数是n^2的做法
  因此需要统计小半部分的和low_sum和大半部分的和high_sum，这样可以O(1)求得步数
*/
/* lc.295寻找数据流的中位数
采用两个优先队列存小半部分和大半部分,中位数偶数时中间两个任选一个
小半部分是大顶堆，从大到小;大半部分是小顶堆，从小到大
默认low可以比high多存一个元素
void addNum(int num) {
    low.push(num);
    high.push(low.top());
    low.pop();
    if (low.size()<high.size())
    {
        low.push(high.top());
        high.pop();
    }
}
*/
typedef long long ll;
class Solution {
    long long mod=1e9+7;
public:
    vector<int> numsGame(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size<=1)
            return {0};
        for (int i=0;i<nums_size;++i)
            nums.at(i)-=i;
        priority_queue <int,vector<int>,less<int>> low;
        priority_queue <int,vector<int>,greater<int>> high;
        ll low_sum=0,high_sum=0;
        ll low_size,hight_size;
        vector<int> ans(nums_size);
        for (int i=0;i<nums_size;++i)
        {
            low.push(nums.at(i));
            low_sum+=nums.at(i);
            high.push(low.top());
            high_sum+=low.top();
            low_sum-=low.top();
            low.pop();
            if (low.size()<high.size())
            {
                low.push(high.top());
                low_sum+=high.top();
                high_sum-=high.top();
                high.pop();
            }
            ll mid=low.top();
            low_size=low.size();
            hight_size=high.size();
            ans.at(i)=((low_size*mid-low_sum)%mod+(high_sum-hight_size*mid)%mod)%mod;
        }
        return ans;
    }
};
