class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows<1)
            return {};
        else if (numRows==1)
            return {{1}};
        vector<vector<int>> answer(numRows,vector<int>({}));
        answer.at(0)={1};
        for (int i=1;i<numRows;++i)
        {
            answer.at(i).push_back(int(1));
            for (int j=1;j<i;++j)
                answer.at(i).push_back(answer.at(i-1).at(j-1)+answer.at(i-1).at(j));
            answer.at(i).push_back(int(1));
        }
        return answer;
    }
};
