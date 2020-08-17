//first存当前剩余橘子，second表示用了几步
typedef pair<int,int> pii;
class Solution {
public:
    int minDays(int n) {
        unordered_set<int> path;
        queue<pii> pq;
        pq.push({n,0});
        while (!pq.empty())
        {
            auto [num,count]=pq.front();
            pq.pop();
            if (path.find(num)!=path.end())
                continue;
            if (num==0)
            {
                return count;
            }
            path.insert(num);
            if (num%3==0)
                pq.push({num-num/3*2,count+1});
            if (num%2==0)
                pq.push({num/2,count+1});
            pq.push({num-1,count+1});
        }
        return -1;
    }
};
// 84806671 32
