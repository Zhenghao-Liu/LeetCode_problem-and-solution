class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int days_size=days.size();
        if (days_size==0)
            return 0;
        vector<int> dp(days.back()+1,0);
        for (int &i:days)
            dp.at(i)=INT_MAX;
        int dp_size=dp.size();
        for (int i=1;i<dp_size;++i)
        {
            if (dp.at(i)==0)
            {
                dp.at(i)=dp.at(i-1);
                continue;
            }
            int costs_1=dp.at(i-1)+costs.at(0);
            int costs_7 = i-7>=0 ? dp.at(i-7)+costs.at(1) : costs.at(1);
            int costs_30 = i-30>=0 ? dp.at(i-30)+costs.at(2) : costs.at(2);
            dp.at(i)=min(costs_1,min(costs_7,costs_30));
        }
        return dp.back();
    }
};
