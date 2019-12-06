class Solution {
public:
int calculateMinimumHP(vector<vector<int>>& dungeon) 
{
	int row=dungeon.size(),column=dungeon.at(0).size();
	//当前格子到达公主需要的最小生命值
	vector<vector<int>> dp (row,vector<int>(column));
	dp.at(row-1).at(column-1)=dungeon.at(row-1).at(column-1)<0?1-dungeon.at(row-1).at(column-1):1;
    for (int i=row-2;i>=0;--i)
    {
        dp.at(i).at(column-1)=dp.at(i+1).at(column-1)-dungeon.at(i).at(column-1);
        if (dp.at(i).at(column-1)<=0)
            dp.at(i).at(column-1)=1;
    }
    for (int i=column-2;i>=0;--i)
    {
        dp.at(row-1).at(i)=dp.at(row-1).at(i+1)-dungeon.at(row-1).at(i);
        if (dp.at(row-1).at(i)<=0)
            dp.at(row-1).at(i)=1;
    }
    for (int i=row-2;i>=0;--i)
        for (int j=column-2;j>=0;--j)
        {
            dp.at(i).at(j)=min(dp.at(i+1).at(j)-dungeon.at(i).at(j),dp.at(i).at(j+1)-dungeon.at(i).at(j));
            if (dp.at(i).at(j)<=0)
                dp.at(i).at(j)=1;
        }
	return dp.at(0).at(0);
}
};
