typedef pair<int,int> pii;
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        //当前可以选择项目的利润，大顶堆
        priority_queue<int> can_profits;
        //first存启动资金，second存利润，小顶堆
        priority_queue<pii,vector<pii>,greater<pii>> not_capital;
        int size=Profits.size();
        for (int i=0;i<size;++i)
            not_capital.push({Capital.at(i),Profits.at(i)});
        for (int i=0;i<k;++i)
        {
            while(!not_capital.empty() && not_capital.top().first<=W)
            {
                can_profits.push(not_capital.top().second);
                not_capital.pop();
            }
            if (can_profits.empty())
                return W;
            W+=can_profits.top();
            can_profits.pop();
        }
        return W;
    }
};
