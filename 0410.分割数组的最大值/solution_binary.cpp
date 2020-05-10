//最后分得的每个数组的和的最大值必然在[max_of_nums,sum_of_nums]中，不断二分去缩小范围
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long sum=0;
        int max_num=INT_MIN;
        int nums_size=nums.size();
        for (int &i:nums)
        {
            sum+=i;
            if (i>max_num)
                max_num=i;
        }
        long long left=max_num,right=sum;
        while (left<right)
        {
            int mid=left+(right-left)/2;
            long long part_sum=0;
            int try_m=1;
            for (int &i:nums)
            {
                part_sum+=i;
                if (part_sum>mid)
                {
                    part_sum=i;
                    ++try_m;
                }
            }
            if (try_m>m)
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
};
