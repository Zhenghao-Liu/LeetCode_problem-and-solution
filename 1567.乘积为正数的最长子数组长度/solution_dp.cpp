/*
* a表示包括nums[i]的最长乘积为正数的序列长度
  b表示包括nums[i]的最长乘积为负数的序列长度
* 注意分界为0的情况
  此时负数正数都有可能无法连续
*/
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int size=nums.size();
        int a=0,b=0;
        int ans=0;
        if (nums.at(0)>0)
            a=1;
        else if (nums.at(0)<0)
            b=1;
        ans=a;
        for (int i=1;i<size;++i)
        {
            int p_a=a,p_b=b;
            if (nums.at(i)>0)
            {
                ++a;
                if (p_b!=0)
                    b=p_b+1;
                else
                    b=0;
                
            }
            else if (nums.at(i)<0)
            {
                if (p_b!=0)
                    a=p_b+1;
                else
                    a=0;
                b=p_a+1;
            }
            else
            {
                a=b=0;
            }
            ans=max(ans,a);
        }
        return ans;
    }
};
