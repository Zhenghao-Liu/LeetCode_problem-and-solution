/*
* 对于[a b c]的数组(a<b<c)满足互相整除，若n%c==0则[a b c n]必然也是一个整除子集
                                      若a%m==0则[m a b c]必然也是一个整除子集
* 通过dp的方法O(n^2)求最大值，dp[i]表示以nums[i]为整除子集最后一位数时的大小
* 但本题要求要输出，所以再借用last数组记录以nums[i]为整除子集最后一位数时，上一位数的索引
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return {};
        vector<int> dp(nums_size,1);
        vector<int> last(nums_size);
        sort(nums.begin(),nums.end());
        int max=1,pos=0;
        for (int i=1;i<nums_size;++i)
        {
            for (int j=0;j<i;++j)
                if (nums.at(i)%nums.at(j)==0 && dp.at(i)<dp.at(j)+1)
                {
                    dp.at(i)=dp.at(j)+1;
                    last.at(i)=j;
                }
            if (dp.at(i)>max)
            {
                max=dp.at(i);
                pos=i;
            }
        }
        vector<int> ans;
        while (max>0)
        {
            ans.push_back(nums.at(pos));
            pos=last.at(pos);
            --max;
        }
        return ans;
    }
};
