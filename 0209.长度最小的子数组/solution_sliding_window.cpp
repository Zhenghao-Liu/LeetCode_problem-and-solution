class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size<1)
            return 0;
        //设置滑块为左闭右开
        int left=0,right=0,answer=INT_MAX,sum=0;
        //left这个条件可加可不加
        while (left<nums_size && right<nums_size)
        {
            while (sum<s && right<nums_size)
            {
                sum=sum+nums.at(right);
                ++right;
            }
            if (sum>=s && right-left<answer)
                answer=right-left;
            //left<=right这个=可加可不加，因为left=right意味着为空
            while (sum>=s && left<=right)
            {
                if (right-left<answer)
                    answer=right-left;
                sum=sum-nums.at(left);
                ++left;
            }
        }
        return answer==INT_MAX?0:answer;
    }
};
