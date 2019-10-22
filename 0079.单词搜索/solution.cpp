class Solution {
public:
bool exist(vector<vector<char>>& board, string word) {
	int row=board.size();
	if (row<1)
		return false;
	int column=board.at(0).size(),word_size=word.size();
	if (row*column<word_size)
		return false;
	else if (word_size<1)
		return true;
	vector<vector<int>> letter_show_path;
	int path_size;
	for (int i=0;i<row;++i)
		for (int j=0;j<column;++j)
			if (board.at(i).at(j)==word.at(0))
			{
				path_size=0;
				letter_show_path.assign(row,vector<int>(column,0));
				back(board,letter_show_path,path_size,row,column,i,j,word);
				if (path_size==word_size)
					return true;
			}
	return false;
}
bool back(vector<vector<char>>& board,vector<vector<int>>& letter_show_path,int &path_size,
			const int&row,const int &column,int i,int j,string &word)
{
	letter_show_path.at(i).at(j)=1;
	++path_size;
	if (path_size==word.size())
		return true;
	//TODO:down
	if (i+1<row && letter_show_path.at(i+1).at(j)==0 && board.at(i+1).at(j)==word.at(path_size))
		if (back(board,letter_show_path,path_size,row,column,i+1,j,word))
			return true;
	//TODO:right
	if (j+1<column && letter_show_path.at(i).at(j+1)==0 && board.at(i).at(j+1)==word.at(path_size))
		if (back(board,letter_show_path,path_size,row,column,i,j+1,word))
			return true;
	//TODO:up
	if (i-1>-1 && letter_show_path.at(i-1).at(j)==0 && board.at(i-1).at(j)==word.at(path_size))
		if (back(board,letter_show_path,path_size,row,column,i-1,j,word))
			return true;
	//TODO:left
	if (j-1>-1 && letter_show_path.at(i).at(j-1)==0 && board.at(i).at(j-1)==word.at(path_size))
		if (back(board,letter_show_path,path_size,row,column,i,j-1,word))
			return true;
	letter_show_path.at(i).at(j)=0;
	--path_size;
	return false;;
}
};
