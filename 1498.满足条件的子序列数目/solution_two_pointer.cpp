/*
* 因为子序列可以是不连续的，所以滑窗别想了，先排序预处理
* 要min+max<=target显然是双指针问题
* 则左端为min，找右端最大满足条件的max
* 如果左端向右移了，即min变大了，意味着要想不等式成立，max要么不动要么左移，所以不用重复走
* 如果我已经确定了左端和右端[a b c d]
  那么我要满足min+max<=target，我是必须要拿min即a的，这样就保证了不等式成立
  但是对于b c d我可拿可不拿，所以一共有2^3种情况
* 因为数据量过大求2^n会溢出所以用快速幂或提前缓存
*/
class Solution {
    int base=1e9+7;
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int nums_size=nums.size();
        int right=nums_size-1;
        int left=0;
        while (left<=right)
        {
            while (left<=right && nums.at(left)+nums.at(right)>target)
                --right;
            if (left>right)
                break;
            ans+=quick_pow(2,right-(left+1)+1);
            ans%=base;
            ++left;
        }
        return ans;
    }
    int quick_pow(int a,int n)
    {
        if (a==0)
            return 0;
        if (n==0)
            return 1;
        a%=base;
        if ((n&1)==1)
            return a*quick_pow(a,n-1)%base;
        else
        {
            int half=quick_pow(a,n/2);
            return (long long)half*half%base;
        }
    }
};
