//二分答案
class Solution {
public:
    int minTime(vector<int>& time, int m) {
        int time_size=time.size();
        if (m>=time_size)
            return 0;
        long l = 0, h = 0;
        for (auto& i : time)
        {
            h += i;
            //if (i>l)
            //    l=i;
        }
        while (l<h)
        {
            long mid = (l + h) / 2;
            long temp = 0;
            int cnt = 1;
            int max=INT_MIN;
            for(auto& i:time)
            {
                temp += i;
                if (i>max)
                    max=i;
                if(temp-max>mid)
                {
                    temp = i;
                    max=i;
                    ++cnt;
                }
            }
            if(cnt>m)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
};
