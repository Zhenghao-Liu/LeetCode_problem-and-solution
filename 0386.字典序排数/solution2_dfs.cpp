class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        dfs(0,ans,n);
        return ans;
    }
    void dfs(int num,vector<int> &ans,const int &n)
    {
        if (num>n)
            return;
        if (num!=0)
            ans.push_back(num);
        int next_num;
        for (int i=0;i<=9;++i)
        {
            next_num=num*10+i;
            if (next_num>0)
                dfs(next_num,ans,n);
        }
    }
};
