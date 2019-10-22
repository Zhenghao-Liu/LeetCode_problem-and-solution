class Solution {
public:
int jump(vector<int>& nums) 
{
    int nums_size=nums.size(),jump_times=0;
	if (nums_size<=1)
		return jump_times;
	int now_position=0,max_distance,best_choice_distance,best_choice_position;
	while (now_position<nums_size-1)
	{
		max_distance=nums.at(now_position);
        if (now_position+max_distance>=nums_size-1)
			return jump_times+1;
		best_choice_distance=0;
		for (int i=1;i<=max_distance && now_position+i<nums_size;++i)
			if (best_choice_distance<=nums.at(now_position+i)+i)
				{
					best_choice_distance=nums.at(now_position+i)+i;
					best_choice_position=i;
				}
		++jump_times;
		now_position=now_position+best_choice_position;
	}
	return jump_times;
}
};
