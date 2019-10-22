class Solution {
public:
bool canJump(vector<int>& nums)
{
	int nums_size=nums.size();
	if (nums_size<2)
		return true;
	else if (nums.at(0)==0)
		return false;
	int max_number_of_additions=0;
	for (int i=0;i<nums_size;++i)
	{
		--max_number_of_additions;
		if (nums.at(i)!=0)
		{
			max_number_of_additions=max(max_number_of_additions,nums.at(i));
			if (i+max_number_of_additions>=nums_size-1)
				return true;
		}
		else if (max_number_of_additions==0)
			return false;
	}
    //最后一个return没有任何意义
    return false;
}
};
