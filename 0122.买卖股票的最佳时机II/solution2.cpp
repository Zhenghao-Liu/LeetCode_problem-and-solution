/*
* 神奇的算法
* 根据题目的意思，当天卖出以后，当天还可以买入
* 例子[1,2,3,4,5]
* (5-1)=(2-1)+(3-2)+(4-3)+(5-4)
* 所以简化为只要今天比昨天大，就卖出。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prices_size=prices.size();
        if (prices_size<2)
            return 0;
        int answer=0;
        for (int i=1;i<prices_size;++i)
            if (prices.at(i)>prices.at(i-1))
                answer=answer+prices.at(i)-prices.at(i-1);
        return answer;
    }
};
