class Solution {
public:
bool canJump(vector<int>& nums)
{
	int nums_size=nums.size();
	if (nums_size<2)
		return true;
	else if (nums.at(0)==0)
		return false;
	//judge,1:成功,2:可能成功,0:失败
	int the_empty_right,judge=1;
	for (int i=nums_size-2;i>0;--i)
		if(nums.at(i)==0)
		{
			if (judge==1)
				the_empty_right=i;
			while(i>0 && nums.at(i-1)==0)
				--i;
			judge=0;
			while(i>0 && nums.at(i-1)!=0)
			{
				--i;
				if (nums.at(i)>the_empty_right-i)
				{
					judge=1;
					break;
				}
			}
			if (judge==1)
				continue;
			else if (i>0 && nums.at(i-1)==0)
				judge=2;
		}
	if (judge!=1)
		return false;
	else
		return true;
}
};
