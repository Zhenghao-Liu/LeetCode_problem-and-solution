/*
* 基于上一题的一次遍历修改
* 可以理解为一个刚开始为全部范围的窗口
* 然后左端不断往右移
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prices_size=prices.size();
        if (prices_size<2)
            return 0;
        int min=prices.at(0),max=prices.at(0),answer=0;
        for (int i=1;i<prices_size;++i)
            if (prices.at(i)>max)
                max=prices.at(i);
            else
            {
                answer=answer+max-min;
                max=min=prices.at(i);
            }     
        return answer+max-min;
    }
};
