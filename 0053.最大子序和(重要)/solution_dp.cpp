/*
* 当前面的额总和<=0时，那加上前面的部分只会使总和变小，所以不如从自己重新开始
* 例如{-2,1,0,1}，1就不需要前面的-2，从自己重新开始
*/
class Solution {
public:
int maxSubArray(vector<int>& nums) 
{
    int nums_size=nums.size();
	if (nums_size<1)
		return 0;
	int sum=nums.at(0),max_sub_sum=sum;
	for (int i=1;i<nums_size;++i)
	{
		if (sum<=0)
			sum=nums.at(i);
		else
			sum=sum+nums.at(i);
		max_sub_sum=max(sum,max_sub_sum);
	}
	return max_sub_sum;
}
};
