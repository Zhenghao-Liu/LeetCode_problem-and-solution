//方法同solution1，贪心模拟，采用堆优化
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for (char &i:tasks)
            ++count.at(i-'A');
        priority_queue<int> helper;
        for (int i:count)
            if (i!=0)
                helper.push(i);
        int ans=0;
        vector<int> unfinfish;
        while (!helper.empty())
        {
            for (int i=0;i<=n;++i)
            {
                if (!unfinfish.empty() && unfinfish.at(0)==0)
                    break;
                if (!helper.empty())
                {
                    unfinfish.push_back(helper.top()-1);
                    helper.pop();
                }
                ++ans;
            }
            int unfinfish_size=unfinfish.size();
            for (int i=0;i<unfinfish_size;++i)
            {
                if (unfinfish.back()!=0)
                    helper.push(unfinfish.back());
                unfinfish.pop_back();
            }
        }
        return ans;
    }
};
