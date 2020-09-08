class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int ans=0;
        vector<vector<bool>> use(n,vector<bool>(n,false));
        for (int i=0;i<n;++i)
        {
            ans+=mat.at(i).at(i);
            use.at(i).at(i)=true;
        }
        for (int i=n-1;i>=0;--i)
        {
            if (!use.at(n-i-1).at(i))
                ans+=mat.at(n-i-1).at(i);
        }
        return ans;
    }
};
