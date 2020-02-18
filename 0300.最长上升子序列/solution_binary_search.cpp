class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int nums_size=nums.size();
        int pile=0;
        vector<int> top(nums_size);
        for (int i=0;i<nums_size;++i)
        {
            int left=0,right=pile;
            while(left<right)
            {
                int mid=left+(right-left)/2;
                if (nums.at(i)>top.at(mid))
                    left=mid+1;
                else if (nums.at(i)<top.at(mid))
                    right=mid;
                else
                {
                    left=mid;
                    break;
                }
            }
            top.at(left)=nums.at(i);
            if (left==pile)
                ++pile;
        }
        return pile;
    }
};
