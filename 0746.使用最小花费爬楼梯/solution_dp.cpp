class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size=cost.size();
        vector<int> dp(size,0);
        dp.at(0)=cost.at(0);
        dp.at(1)=cost.at(1);
        for (int i=2;i<size;++i)
            dp.at(i)=min(dp.at(i-1),dp.at(i-2))+cost.at(i);
        return min(dp.at(size-1),dp.at(size-2));
    }
};
