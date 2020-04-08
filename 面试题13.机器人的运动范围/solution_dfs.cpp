class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> map(m,vector<int>(n,0));
        int ans=0;
        dfs(map,m,n,k,0,0,ans);
        return ans;
    }
    void dfs(vector<vector<int>> &map,const int & m,const int & n,const int & k,int i,int j,int & ans)
    {
        if (count(i)+count(j)<=k)
        {
            ++ans;
            map.at(i).at(j)=1;
        }
        else
        {
            map.at(i).at(j)=-1;
            return;
        }
        //数组向下，对应坐标轴向上
        if (i+1<m && map.at(i+1).at(j)==0)
            dfs(map,m,n,k,i+1,j,ans);
        //数组向右，对应坐标向右
        if (j+1<n && map.at(i).at(j+1)==0)
            dfs(map,m,n,k,i,j+1,ans);
    }
    int count(int num)
    {
        int ans=0;
        while (num!=0)
        {
            ans+=num%10;
            num/=10;
        }
        return ans;
    }
};
