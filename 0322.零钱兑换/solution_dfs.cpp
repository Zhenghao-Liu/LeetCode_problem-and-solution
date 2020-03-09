class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //采用rbegin和rend来让数组按照降序排列
        sort(coins.rbegin(),coins.rend());
        int answer=INT_MAX;
        dfs(coins,amount,0,0,answer);
        return answer==INT_MAX ? -1 : answer;
    }
    void dfs(vector<int> & coins,int amount,int count,int index,int & answer)
    {
        if (amount==0)
        {
            answer=min(answer,count);
            return;
        }
        if (index>=coins.size())
            return;
        //i+count<answer剪枝，巨优化效率
        for (int i=amount/coins.at(index);i>=0 && i+count<answer;--i)
            dfs(coins,amount-i*coins.at(index),count+i,index+1,answer);
    }
};
