//暴力
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size<1)
            return 0;
        int answer=INT_MAX;
        for (int i=0;i<nums_size;++i)
        {
            int sum=0,j;
            for (j=i;j<nums_size && sum<s;++j)
                sum=sum+nums.at(j);
            if (sum>=s && j-i<answer)
                answer=j-i;
        }
        return answer==INT_MAX?0:answer;
    }
};
