class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty())
            return 0;
        int ans=0;
        int timeSeries_size=timeSeries.size();
        for (int i=0;i<timeSeries_size-1;++i)
            ans+=min(timeSeries.at(i+1)-timeSeries.at(i),duration);
        return ans+duration;
    }
};
