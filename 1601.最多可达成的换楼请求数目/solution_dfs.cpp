//可直接dfs回溯求是否用该条边
class Solution {
    vector<int> vec;
    int ans;
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int size=requests.size();
        vec=vector<int>(n);
        ans=0;
        dfs(requests,0,0);
        return ans;
    }
    void dfs(vector<vector<int>>& requests,int start,int cur)
    {
        int n=vec.size();
        int a;
        for (a=0;a<n;++a)
            if (vec.at(a)!=0)
                break;
        if (a==n)
        {
            ans=max(ans,cur);
        }
        int size=requests.size();
        for (int i=start;i<size;++i)
        {
            ++vec.at(requests.at(i).at(1));
            --vec.at(requests.at(i).at(0));
            dfs(requests,i+1,cur+1);
            --vec.at(requests.at(i).at(1));
            ++vec.at(requests.at(i).at(0));
        }
    }
};
