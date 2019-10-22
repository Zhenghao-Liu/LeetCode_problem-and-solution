//抖抖机灵就好了，不建议用此方法
class Solution {
public:
    string getPermutation(int n, int k) 
	{
        vector<int> nums;
        for (int i=1;i<=n;++i)
            nums.push_back(i);
        for (int i=1;i<k;++i)
			next_permutation(nums.begin(),nums.end());
		string answer;
		for (int i=0;i<n;++i)
			answer=answer+char(nums.at(i)+'0');
        return answer;
    }
};
