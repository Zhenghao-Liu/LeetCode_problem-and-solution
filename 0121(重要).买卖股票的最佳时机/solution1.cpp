class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prices_size=prices.size();
        if (prices_size<2)
            return 0;
        int min=prices.at(0),max=prices.at(0),answer=INT_MIN;
        for (int i=1;i<prices_size;++i)
            if (prices.at(i)>max)
            {
                max=prices.at(i);
                if (max-min>answer)
                    answer=max-min;
            }
            else if (prices.at(i)<min)
                min=max=prices.at(i);
        return answer==INT_MIN?0:answer;
    }
};
