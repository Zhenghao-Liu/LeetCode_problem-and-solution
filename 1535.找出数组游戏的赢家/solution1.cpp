//模拟
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int size=arr.size();
        if (k>=size)
            return *max_element(arr.begin(),arr.end());
        deque<int> d(arr.begin(),arr.end());
        int cur=0;
        while (cur<k)
        {
            if (d.at(0)>d.at(1))
            {
                int t=d.at(1);
                auto p=d.begin();
                ++p;
                d.erase(p);
                d.push_back(t);
                ++cur;
            }
            else
            {
                int t=d.at(0);
                d.pop_front();
                cur=1;
                d.push_back(t);
            }
        }
        return d.at(0);
    }
};
