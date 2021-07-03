class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        return dfs(mat,target,0);
    }
    bool dfs(vector<vector<int>>& mat, vector<vector<int>>& tar,int cnt) {
        if (mat==tar) {
            return true;
        }
        if (cnt>=4) {
            return false;
        }
        int n=mat.size();
        vector<vector<int>> vec(n,vector<int>(n));
        for (int j=0;j<n;j++) {
            for (int i=n-1;i>=0;i--) {
                vec.at(j).at(n-1-i)=mat.at(i).at(j);
            }
        }
        return dfs(vec,tar,cnt+1);
    }
};