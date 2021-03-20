/*
 * 题目要求 du[a]+du[b]-connected[a][b]>queries[i]的个数
 * 因为n是2e4  edges.size()是1e5 都很大
 * 可以换一种角度求:容斥原理
 * 1. 先求出du[a]+du[b]>queries[i]的个数设为res1
   2. 再求出du[a]+du[b]-connected[a][b]<=queries[i]的个数设为res2
   3. 最后答案就是res1-res2
 * 但是connected[a][b]数据量过于太大，所以采用edges.size()大小来存，即通过map来存
 * 那么怎么求res1呢，可以对du进行排序，
   转化成一个问题：在升序序列中，找出两个数的和大于目标值的可能数
   就是一个基础的双指针问题
 * 怎么求res2呢，去枚举所有边即可
 * 时间复杂度O(n + nlogn + queries.size() * ( n + edges.size() ) ) 在e6左右
 */
typedef pair<int,int> pii;
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> du(n);
        map<pii,int> mp;
        for (vector<int> &i:edges) {
            int u=i.at(0)-1,v=i.at(1)-1;
            du.at(u)++;
            du.at(v)++;
            if (u>v) {
                swap(u,v);
            }
            mp[{u,v}]++;
        }
        vector<int> sortDu(du);
        sort(sortDu.begin(),sortDu.end());
        int queSz=queries.size();
        vector<int> ans(queSz);
        for (int i=0;i<queSz;i++) {
            int upper=0;
            int que=queries.at(i);
            int l=0,r=n-1;
            for (l=0;l<n-1;++l) {
                while (l<r && sortDu.at(l)+sortDu.at(r)>que) {
                    r--;
                }
                upper+=min(n-1-r,n-1-l);
            }
            int lower=0;
            for (auto &i:mp) {
                auto [u,v]=i.first;
                int cnt=i.second;
                if (du.at(u)+du.at(v)>que && du.at(u)+du.at(v)-cnt<=que) {
                    lower++;
                }
            }
            ans.at(i)=upper-lower;
        }
        return ans;
    }
};
