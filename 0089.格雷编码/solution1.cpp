/*
* 这种方法基于格雷码是反射码的事实，利用递归的如下规则来构造：
* 1位格雷码有两个码字
* (n+1)位格雷码中的前2n个码字等于n位格雷码的码字，按顺序书写，加前缀0
* (n+1)位格雷码中的后2n个码字等于n位格雷码的码字，按逆序书写，加前缀1
* n+1位格雷码的集合 = n位格雷码集合(顺序)加前缀0 + n位格雷码集合(逆序)加前缀1
*/
class Solution {
public:
vector<int> grayCode(int n) 
{
	if (n==0)
		return {0};
	vector<string> temporary;
	int temporary_size;
	vector<string> str_gray({"0","1"});
	for (int i=1;i<n;++i)
	{
		temporary=str_gray;
		str_gray.clear();
		temporary_size=temporary.size();
		for (int j=0;j<temporary_size;++j)
			str_gray.push_back(string("0"+temporary.at(j)));
		for (int j=0;j<temporary_size;++j)
			str_gray.push_back(string("1"+temporary.at(temporary_size-j-1)));
	}
	int str_gray_size=str_gray.size();
	vector<int> answer(str_gray_size,0);
	for (int i=0;i<str_gray_size;++i)
		for (int j=0;j<n;++j)
			answer.at(i)=answer.at(i)+(str_gray.at(i).at(j)-'0')*pow(2,n-j-1);
	return answer;
}
};
