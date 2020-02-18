class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return 0;
        vector<int> dp(nums_size,1);
        int answer=INT_MIN;
        for (int i=0;i<nums_size;++i)
        {
            for (int j=0;j<i;++j) 
                if (nums.at(i)>nums.at(j))
                    dp.at(i)=max(dp.at(i),dp.at(j)+1);
            if (dp.at(i)>answer)
                answer=dp.at(i);
        }
        return answer;
    }
};
