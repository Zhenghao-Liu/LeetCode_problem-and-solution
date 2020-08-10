/*
* 贪心：尽可能的在一个周期内多做不同的任务，且一旦冷冻期结束，那么尽可能做任务次数较多的那个任务
* 采用模拟的方式
*/
typedef pair<int,int> pii;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for (char &i:tasks)
            ++count.at(i-'A');
        priority_queue<int> helper;
        for (int i=0;i<26;++i)
            if (count.at(i)!=0)
                helper.push(count.at(i));
        int ans=0;
        deque<pii> freeze;
        while (!helper.empty() || !freeze.empty())
        {
            ++ans;
            for (pii &i:freeze)
                --i.second;
            if (!helper.empty())
            {
                int unfinish=helper.top();
                --unfinish;
                helper.pop();
                if (unfinish!=0)
                    freeze.push_back({unfinish,n});
            }
            if (!freeze.empty() && freeze.at(0).second==0)
            {
                helper.push(freeze.at(0).first);
                freeze.pop_front();
            }
        }
        return ans;
    }
};
