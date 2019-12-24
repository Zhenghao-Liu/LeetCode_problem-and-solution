class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        if (row==0)
            return 0;
        int column=matrix.at(0).size();
        int answer=0;
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (matrix.at(i).at(j)=='1')
                {
                    int long_1=0,temporary_j=j;
                    while (temporary_j>=0 && matrix.at(i).at(temporary_j)=='1')
                    {
                        ++long_1;
                        --temporary_j;
                    }
                    int height_1=0,temporary_i=i;
                    while (temporary_i>=0 && matrix.at(temporary_i).at(j)=='1')
                    {
                        ++height_1;
                        --temporary_i;
                    }
                    int max_possible=min(long_1,height_1);
                    bool find_square=false;
                    while (!find_square)
                    {
                        find_square=true;
                        temporary_i=i;
                        temporary_j=j;
                        for (int i_i=temporary_i;find_square && temporary_i-i_i<max_possible;--i_i)
                            for (int j_j=temporary_j;temporary_j-j_j<max_possible;--j_j)
                                if (matrix.at(i_i).at(j_j)!='1')
                                {
                                    --max_possible;
                                    find_square=false;
                                    break;
                                }
                    }
                    if (max_possible*max_possible>answer)
                        answer=max_possible*max_possible;
                }
        return answer;
    }
};
