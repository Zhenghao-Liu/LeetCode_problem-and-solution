class Solution {
    unordered_map<int,char> helper;
public:
    string largestNumber(vector<int>& cost, int target) {
        helper.clear();
        //贪心：对于同样的成本数字越大越好
        for (int i=0;i<9;++i)
            helper[cost.at(i)]=char(i+1+'0');
        //dp[i]表示总的成本为i时构建最大数字的成本是多少
        vector<string> dp(target+1);
        for (int i=1;i<=target;++i)
        {
            for (auto &j:helper)
                if (i-j.first>=0)
                {
                    //一定要注意不为空的情况，因为i-j.first如果不等于0，且还为空
                    //说明无法构建该target=i-j.first情况下的成本数字
                    if (i!=j.first && !dp[i-j.first].empty())
                    {
                        //因为用了引用加速，也可以直接复制构造也能过
                        dp[i-j.first].push_back(j.second);
                        if (bigger(dp[i-j.first],dp[i]))
                            dp[i]=dp[i-j.first];
                        dp[i-j.first].pop_back();
                    }
                    //一定要分开写，因为此时target=0，空代表的是target为0时不需要成本，这时候空有意义
                    if (i==j.first)
                    {
                        dp[0].push_back(j.second);
                        if (bigger(dp[0],dp[i]))
                            dp[i]=j.second;
                        dp[0].pop_back();
                    }
                }
        }
        if (dp[target].empty())
            return "0";
        return dp[target];
    }
    bool bigger(string &a,string &b)
    {
        if (a.size()!=b.size())
            return a.size()>b.size();
        int size=a.size();
        for (int i=0;i<size;++i)
            if (a[i]==b[i])
                continue;
            else 
                return a[i]>b[i];
        return false;
    }
};
