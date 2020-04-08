class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> helper;
        helper.push(make_pair(0,0));
        visited.at(0).at(0)=true;
        int ans=0;
        while (!helper.empty())
        {
            int x=helper.front().first;
            int y=helper.front().second;
            helper.pop();
            if (count(x)+count(y)<=k)
            {
                ++ans;
                if (x+1<m && !visited.at(x+1).at(y))
                {
                    helper.push(make_pair(x+1,y));
                    visited.at(x+1).at(y)=true;
                }
                if (y+1<n && !visited.at(x).at(y+1))
                {
                    helper.push(make_pair(x,y+1));
                    visited.at(x).at(y+1)=true;
                }
                    
            }
        }
        return ans;
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
