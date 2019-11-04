/*
* 采用从顶到下
* dp.at(i).at(j)表示从顶到这个点最小距离
* 注意边界
*/
class Solution {
public:
int minimumTotal(vector<vector<int>>& triangle) 
{
    int triangle_size=triangle.size();
    if (triangle_size==0)
		return 0;
    vector<vector<int>> dp(triangle_size,vector<int>(triangle.at(triangle_size-1).size(),0));
    dp.at(0).at(0)=triangle.at(0).at(0);
    for (int i=1;i<triangle_size;++i)
        for (int j=0;j<=i;++j)
            if (j==0)
                dp.at(i).at(j)=dp.at(i-1).at(j)+triangle.at(i).at(j);
            else if (j==i)
                dp.at(i).at(j)=dp.at(i-1).at(j-1)+triangle.at(i).at(j);
            else
                dp.at(i).at(j)=min(dp.at(i-1).at(j),dp.at(i-1).at(j-1))+triangle.at(i).at(j);
    return *min_element(dp.at(triangle_size-1).begin(),dp.at(triangle_size-1).end());
}
};
