//最后结果排序
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        int size=A.size();
        for (int &i:A)
            if (i<0)
                i=-i;
            else
                break;
        sort(A.begin(),A.end());
        for (int i=0;i<size;++i)
        {
            int n=A.at(i);
            ans.push_back(n*n);
        }
        return ans;
    }
};
