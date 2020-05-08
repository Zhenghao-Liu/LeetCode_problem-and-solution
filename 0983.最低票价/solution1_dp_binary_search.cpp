class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        days.insert(days.begin(),0);
        int days_size=days.size();
        //以第days[i-1]天为结尾的最少钱
        vector<int> dp(days_size,INT_MAX);
        dp.at(0)=0;
        for (int i=1;i<days_size;++i)
        {
            dp.at(i)=dp.at(i-1)+costs.at(0);
            int p7=lower_bound(days.begin()+1,days.begin()+i,days.at(i)-7)-days.begin();
            if (days.at(p7)!=days.at(i)-7)
                dp.at(i)=min(dp.at(i),dp.at(p7-1)+costs.at(1));
            else
                dp.at(i)=min(dp.at(i),dp.at(p7)+costs.at(1));
            int p30=lower_bound(days.begin()+1,days.begin()+i,days.at(i)-30)-days.begin();
            if (days.at(p30)!=days.at(i)-30)
                dp.at(i)=min(dp.at(i),dp.at(p30-1)+costs.at(2));
            else
                dp.at(i)=min(dp.at(i),dp.at(p30)+costs.at(2));
        }
        return dp.back();
    }
};
