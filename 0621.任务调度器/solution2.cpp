//方法同solution1，也是贪心模拟
typedef pair<int,int> pii;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for (char &i:tasks)
            ++count.at(i-'A');
        sort(count.rbegin(),count.rend());
        int ans=0;
        while (count.at(0)!=0)
        {
            for (int i=0;i<=n;++i)
            {
                if (count.at(0)==0)
                    break;
                if (i<26 && count.at(i)>0)
                    --count.at(i);
                ++ans;
            }
            sort(count.rbegin(),count.rend());
        }
        return ans;
    }
};
