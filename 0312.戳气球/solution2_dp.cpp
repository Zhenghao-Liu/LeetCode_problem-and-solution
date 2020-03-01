class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return 0;
        vector<int> nums_m(nums_size+2);
        nums_m.at(0)=1;
        nums_m.at(nums_size+1)=1;
        for (int i=0;i<nums_size;++i)
            nums_m.at(i+1)=nums.at(i);
        vector<vector<int>> dp(nums_size+1,vector<int>(nums_size+2,0));
        for (int i=nums_size;i>=0;--i)
            for (int j=i+1;j<nums_size+2;++j)
            {
                int max=0;
                int temp=nums_m.at(i)*nums_m.at(j);
                for (int k=i+1;k<j;++k)
                {
                    int result=dp.at(i).at(k)+dp.at(k).at(j)+temp*nums_m.at(k);
                    if (result>max)
                        max=result;
                }
                dp.at(i).at(j)=max;
            }
        return dp.at(0).at(nums_size+1);
    }
};
