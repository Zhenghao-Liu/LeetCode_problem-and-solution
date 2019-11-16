//从左到右满足最少的糖果，再找从右到左的，最后取两边都满足的值(就是最大值)。
class Solution {
public:
int candy(vector<int>& ratings) 
{
	int ratings_size=ratings.size();
	vector<int> left_to_right(ratings_size,1);
    vector<int> right_to_left(ratings_size,1);
    for (int i=1;i<ratings_size;++i)
        if (ratings.at(i)>ratings.at(i-1))
            left_to_right.at(i)=left_to_right.at(i-1)+1;
    for (int i=ratings_size-2;i>-1;--i)
        if (ratings.at(i)>ratings.at(i+1))
            right_to_left.at(i)=max(left_to_right.at(i),right_to_left.at(i+1)+1);
	int sum=0;
    for (int i=0;i<ratings_size;++i)
        sum=sum+max(left_to_right.at(i),right_to_left.at(i));
	return sum;
}
};
