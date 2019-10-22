/*
*答案正确但速度比较慢，可以继续优化
*执行用时 :180 ms, 在所有 C++ 提交中击败了6.52%的用户
*内存消耗 :19.9 MB, 在所有 C++ 提交中击败了9.17%的用户
*/
static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> empty_place;
        for (int i=0;i<9;++i)
            for (int j=0;j<9;++j)
                if (board.at(i).at(j)=='.')
                    empty_place.push_back(vector<int>({i,j}));
	    fill_board(board,empty_place,0,empty_place.size());
    }
    bool fill_board(vector<vector<char>>& board,vector<vector<int>>& empty_place,int position_number,const int& empty_place_number)
    {
	    if (position_number==empty_place_number)
		    return true;
	    vector<char> possible_char(look_for_possible(board,empty_place.at(position_number).at(0),empty_place.at(position_number).at(1)));
	    int possible_char_size=possible_char.size();
	    if (possible_char_size==0)
		    return false;
	    for (int i=0;i<possible_char_size;++i)
	    {
		    board.at(empty_place.at(position_number).at(0)).at(empty_place.at(position_number).at(1))=possible_char.at(i);
		    if (fill_board(board,empty_place,position_number+1,empty_place_number))
			    return true;
		    else
			    board.at(empty_place.at(position_number).at(0)).at(empty_place.at(position_number).at(1))='.';		
	    }
	    return false;	
    }
    vector<char> look_for_possible(const vector<vector<char>>& board,const int row,const int column)
    {
	    char value; 
	    string possible_string="";
	    for (int i=0;i<9;++i)
	    {
		    value=board.at(row).at(i);
		    if (value!='.')
			    possible_string=possible_string+value;
		    value=board.at(i).at(column);
		    if (value!='.')
			    possible_string=possible_string+value;
	    }
	    int row_right=row/3*3+3,column_right=column/3*3+3;
        for(int i=row/3*3;i<row_right;++i)
		    for(int j=column/3*3;j<column_right;++j)
		    {
			    value=board.at(i).at(j);
			    if (value!='.')
				    possible_string=possible_string+value;
		    }
	    vector<char> possible_char;
	    for (int i=1;i<10;++i)
		    if (possible_string.find(i+'0')==string::npos)
			    possible_char.push_back(char(i+'0'));
	    return possible_char;
    }
};
