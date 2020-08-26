/*
* 首先乘2肯定比加1的增加更快
* 且最终变成大数的a，在乘2的过程中可以带着小数一起乘
* 模拟：每次除2，遇到奇数则-1，直到全0为止
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        while (1)
        {
            for (int &i:nums)
                if (i%2==1)
                {
                    --i;
                    ++ans;
                }
            bool judge_zero=false;
            for (int &i:nums)
            {
                if (i!=0)
                    judge_zero=true;
                i/=2;
            }
            if (!judge_zero)
            {
                break;
            }
            ++ans;
        }
        return ans;
    }
};
