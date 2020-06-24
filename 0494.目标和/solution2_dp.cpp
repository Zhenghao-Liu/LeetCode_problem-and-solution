//压缩至一维
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S>1000)
            return 0;
        int nums_size=nums.size();
        vector<int> dp(2001,0);
        vector<int> temp(2001,0);
        dp.at(nums.at(0)+1000)+=1;
        dp.at(-nums.at(0)+1000)+=1;
        for (int i=1;i<nums_size;++i)
        {
            fill(temp.begin(),temp.end(),0);
            for (int j=0;j<2001;++j)
            {
                if (dp.at(j)>0)
                {
                    temp.at(j+nums.at(i))+=dp.at(j);
                    temp.at(j-nums.at(i))+=dp.at(j);
                    
                }
            }
            dp=temp;
        }
        return dp.at(S+1000);
    }
};
