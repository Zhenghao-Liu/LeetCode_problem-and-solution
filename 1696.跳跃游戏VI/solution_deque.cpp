//因为k最大和nums.size一样，采用n^2的dp是不行的，
//因为要在范围内挑选价值最大的地方跳到当前，所以采用单调栈，一个值比你大还在你后面，那你就没用
typedef pair<int,int> pii;
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pii> deq;
        int ans=nums.at(0);
        int size=nums.size();
        deq.push_back({nums.at(0),0});
        for (int i=1;i<size;++i)
        {
            while (!deq.empty() && i-deq.front().second>k)
                deq.pop_front();
            ans=nums.at(i)+deq.front().first;
            while (!deq.empty() && deq.back().first<=ans)
                deq.pop_back();
            deq.push_back({ans,i});
        }
        return ans;
    }
};
