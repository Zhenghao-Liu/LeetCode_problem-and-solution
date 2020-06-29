class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0;
        int max_time=-1;
        for (int i:timeSeries)
        {
            if (i>max_time)
                ans+=duration;
            else
                ans+=i+duration-1-max_time;
            max_time=i+duration-1;
        }
        return ans;
    }
};
