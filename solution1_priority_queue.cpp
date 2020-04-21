vector<vector<int>> static_matrix;
struct cmp
{
    bool operator()(const pair<int,int> &A,const pair<int,int>&B) const
    {
        return static_matrix.at(A.first).at(A.second)>static_matrix.at(B.first).at(B.second);
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int matrix_size=matrix.size();
        if (matrix_size==0)
            return 0;
        static_matrix=matrix;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> helper;
        for (int i=0;i<matrix_size;++i)
            helper.push(make_pair(i,0));
        int x,y;
        while (k>0)
        {
            x=helper.top().first;
            y=helper.top().second;
            helper.pop();
            if (y+1<matrix_size)
                helper.push(make_pair(x,y+1));
            --k;
        }
        return matrix.at(x).at(y);
    }
};
