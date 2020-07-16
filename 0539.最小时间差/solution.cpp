/*
* 因为是分钟做单位，可以把所有时间都换成分钟
* 然后有点像514.自由之路的转盘，即min(j-i,size-(j-i))
* 将时间排序，然后两者之间比较差距即可
* 但是注意一次循环不够，因为还要比较最后一个到达第一个的时间差
*/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        vector<int> time;
        int size=timePoints.size();
        time.reserve(size);
        for (string &i:timePoints)
            time.push_back(stoi(i.substr(0,2))*60+stoi(i.substr(3,2)));
        int one_day=24*60;
        sort(time.begin(),time.end());
        int ans=INT_MAX;
        for (int i=0;i<size-1;++i)
        {
            int a=time.at(i),b=time.at(i+1);
            ans=min(ans,min(b-a,one_day-(b-a)));
            if (ans==0)
                return 0;
        }
        int a=time.at(0),b=time.back();
        ans=min(ans,min(b-a,one_day-(b-a)));
        return ans;
    }
};
