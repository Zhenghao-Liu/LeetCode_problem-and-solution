/*
* 借用题解的想法：这题如果递归就做复杂了，其实是有规律的 (Author: 小许)
*/
class Solution {
public:
string getPermutation(int n, int k)
{
	string nums;
	for (int i=1;i<=n;++i)
		nums.append(1,char(i+'0'));
	string answer;
	int interval,loop_times=n;
	for (int i=0;i<loop_times;++i)
	{
		--n;
        interval=(k-1)/factorial(n);
		answer=answer+nums.at(interval);
		nums.erase(nums.begin()+interval);
		k=k-interval*factorial(n);	
	}
	return answer;
}
int factorial(int x)  
{  
    register int i,f=1; 
    for(i=1;i<=x;i++)  
        f=f*i;  
    return f;  
}
};
