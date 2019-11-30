//看下桶排序题解的数学推论，最后结果就是最大间距一定出现在各个桶之间不在桶里面，所以只用记录桶的最大值和最小值即可
class Solution {
    struct bucket{
        int max_num=INT_MIN;
        int min_num=INT_MAX;
        //万一测试数据用到了INT_MAX或INT_MIN，还是多一个bool保险
        bool have_num=false;
    };
public:
int maximumGap(vector<int>& nums) {
	int nums_size=nums.size();
	if (nums_size<2)
		return 0;
	int min=*min_element(nums.begin(),nums.end()),max=*max_element(nums.begin(),nums.end());
    //当公式去记，gap表示桶内间隔
	int gap=ceil((max-min)/1.0/(nums_size-1));
    //因为有可能出现全为一样数字的情况，这样gap为0，且bucket_size以0为除数会有问题
	if (gap==0)
		return 0;
    //当公式去记，bucket_size表有多少个桶，注意也要向上取整
	int bucket_size=ceil((max-min)/1.0/gap);
	vector<bucket> bucket_nums(bucket_size);
	int index;
	for (int &i:nums)
	{
        //{1,2,3,4,7}中7单独一个桶，只是max_num=min_num=7
        //因为存桶默认是[a,b)的来存，但是对于最后一个桶要存最大值，所以最后一个桶要[a,b]存
        if (i==max)
			index=bucket_size-1;
		else
			index=(i-min)/gap;
		if (bucket_nums.at(index).max_num<i)
			bucket_nums.at(index).max_num=i;   
		if (bucket_nums.at(index).min_num>i)
			bucket_nums.at(index).min_num=i;
		if (!bucket_nums.at(index).have_num)
			bucket_nums.at(index).have_num=true;
	}
    //防止出现[1,2]这种计算出来只有一个桶
	if (bucket_size==1)
		return bucket_nums.at(0).max_num-bucket_nums.at(0).min_num;
	int answer=INT_MIN;
	int j,temporary;
    //用第i个桶的最小值减去第j个桶的最大值
	for (int i=bucket_size-1;i>0;i=j)
	{
		for (j=i-1;j>=0;--j)
			if (bucket_nums.at(j).have_num)
				break;
		temporary=bucket_nums.at(i).min_num-bucket_nums.at(j).max_num;
		if (temporary>answer)
			answer=temporary;
	}
	return answer;
}
};
