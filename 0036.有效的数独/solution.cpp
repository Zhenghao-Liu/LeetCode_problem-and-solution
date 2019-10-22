static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        string horizontal,vertical;
        char value;
        vector<string> block;
        for (int i=0;i<9;++i)
            block.push_back(string(""));
        int block_number;
        for (int i=0;i<9;++i)
        {
            horizontal=vertical="";
            for (int j=0;j<9;++j)
            {
                value=board.at(i).at(j);
                if (value=='.');
                else if (horizontal.find(value)==string::npos)
                    horizontal=horizontal+value;
                else
                    return false;
                block_number=(i/3)*3+j/3;
                if (value=='.');
                else if (block.at(block_number).find(value)==string::npos)
                    block.at(block_number)=block.at(block_number)+value;
                else
                    return false;
                value=board.at(j).at(i);
                if (value=='.')
                    continue;
                else if (vertical.find(value)==string::npos)
                    vertical=vertical+value;
                else
                    return false;
            }
        }
        return true;             
    }
};
