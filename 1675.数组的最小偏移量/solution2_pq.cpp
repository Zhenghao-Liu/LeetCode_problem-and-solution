/*
 * 将问题转化成 632.最小区间
 * 将每个nums的所有取值可能当做分组
 * 且单向即只有*2
 * 枚举所有可能
 */
const int MAXN=100000;
int top[MAXN];
int cur[MAXN];
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int size=nums.size();
        for (int i=0;i<size;++i)
        {
            int ii=nums.at(i);
            if (ii%2==0)
            {
                top[i]=ii;
                while (ii%2==0)
                    ii/=2;
                cur[i]=ii;
            }
            else
            {
                top[i]=ii*2;
                cur[i]=ii;
            }
        }
        auto func=[](const int &A,const int &B){
            return cur[A]>cur[B];
        };
        priority_queue<int,vector<int>,decltype(func)> pq(func);
        int mi=INT_MAX,mx=INT_MIN;
        for (int i=0;i<size;++i)
        {
            pq.push(i);
            mi=min(mi,cur[i]);
            mx=max(mx,cur[i]);
        }
        int ans=mx-mi;
        while (true)
        {
            int idx=pq.top();
            pq.pop();
            cur[idx]*=2;
            if (cur[idx]>top[idx])
                break;
            int digit=cur[idx];
            mx=max(mx,digit);
            pq.push(idx);
            mi=cur[pq.top()];
            ans=min(ans,mx-mi);
        }
        return ans;
    }
};
