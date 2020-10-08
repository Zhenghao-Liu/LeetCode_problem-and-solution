/*
 * 因为是nlogn复杂度，所以自然要支持二分的容器
 * 且要保存正在工作的服务器和空闲的服务器
 * 所以一个堆pq+一个set，set保存空闲服务器，pq保存正在工作服务器
 */
typedef pair<int,int> pii;
const int MAXN=100000;
int cnt[MAXN];
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        memset(cnt,0,sizeof(cnt));
        int size=arrival.size();
        set<int> free_serve;
        for (int i=0;i<k;++i)
            free_serve.insert(i);
        auto func=[](const pii &A,const pii &B)->bool{
            return A.second>B.second;
        };
        priority_queue<pii,vector<pii>,decltype(func)> busy_serve(func);
        for (int i=0;i<size;++i)
        {
            int arr=arrival.at(i),loa=load.at(i);
            while (!busy_serve.empty() && arr>=busy_serve.top().second)
            {
                free_serve.insert(busy_serve.top().first);
                busy_serve.pop();
            }
            int tar=i%k;
            auto it=free_serve.lower_bound(tar);
            if (it==free_serve.end() && !free_serve.empty())
                it=free_serve.begin();
            if (it!=free_serve.end())
            {
                int idx=*it;
                ++cnt[idx];
                free_serve.erase(it);
                busy_serve.push({idx,arr+loa});
            }
        }
        vector<int> ans;
        int c_m=0;
        for (int i=0;i<k;++i)
            if (cnt[i]>c_m)
            {
                c_m=cnt[i];
                ans.clear();
                ans.push_back(i);
            }
            else if (cnt[i]==c_m)
                ans.push_back(i);
        return ans;
    }
};
