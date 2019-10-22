class Solution {
public:
int totalNQueens(int n)
{
	if (n<1 || n==2 || n==3)
        return 0;
	vector<string> board(n);
	for (int i=0;i<n;++i)
		board.at(i).append(n,'.');
	int answer=0;
	place_Queens(answer,n,0,board);
	return answer;
}
bool check_Queens(const vector<string>& board,const int &n,const int &row,const int &column)
{
	for (int i=0;i<n;++i)
	{
		if (i!=row && board.at(i).at(column)=='Q')
			return false;
		/*if (i!=column && board.at(row).at(i)=='Q')
			return false;*/
		if (row-i>0 && column-i>0 && board.at(row-i-1).at(column-i-1)=='Q')//↖
			return false;
		if (row+i+1<n && column+i+1<n && board.at(row+i+1).at(column+i+1)=='Q')//↘
			return false;		
		if (row-i>0 && column+i+1<n && board.at(row-i-1).at(column+i+1)=='Q')//↗
			return false;
		if (row+i+1<n && column-i>0 && board.at(row+i+1).at(column-i-1)=='Q')//↙
			return false;	
	}
	return true;
}
void place_Queens(int& answer,const int& n,const int& row,vector<string> board)
{	
	for(int i=0;i<n;++i)
	{
		if (check_Queens(board,n,row,i))
		{
			board.at(row).at(i)='Q';
			if (row==n-1)
				++answer;
			else
				place_Queens(answer,n,row+1,board);
		}
		board.at(row).at(i)='.';
	}
}
};
