class Solution {
public:
int candy(vector<int>& ratings) {
	int ratings_size=ratings.size();
	vector<int> answer(ratings_size,1);
	get_answer(ratings,answer,0,ratings_size-1);
	int sum=0;
	for (int i:answer)
		sum=sum+i;
	return sum;
}
void get_answer(vector<int>& ratings,vector<int>& answer,int left,int right)
{
	if (left>=right)
		return;
	int left_p,right_p,index;
	left_p=right_p=index=min_element(ratings.begin()+left,ratings.begin()+right+1)-ratings.begin();
	while (right_p!=right && ratings.at(right_p)<ratings.at(right_p+1) && answer.at(right_p)>=answer.at(right_p+1))
	{
		answer.at(right_p+1)=answer.at(right_p)+1;
		++right_p;
	}
	while (left_p!=left && ratings.at(left_p)<ratings.at(left_p-1) && answer.at(left_p)>=answer.at(left_p-1))
	{
		answer.at(left_p-1)=answer.at(left_p)+1;
		--left_p;
	}
	while (left_p!=left && ratings.at(left_p-1)==ratings.at(left_p))
		--left_p;
	while (right_p!=right && ratings.at(right_p+1)==ratings.at(right_p))
		++right_p;
	if (left_p!=index)
		get_answer(ratings,answer,left,left_p);
	if (right_p!=index)
		get_answer(ratings,answer,right_p,right);
}
};
