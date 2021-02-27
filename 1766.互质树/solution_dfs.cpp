/*
 * 1 <= nums[i] <= 50
 * 因为数字最大只有50，可以去枚举所有情况
 * 但是要判断哪个是最近的祖先节点，所以同时还要枚举每个nums[i]的当前深度
 * 再把树当成图，从根节点开始dfs扫一趟，这样保证了之前遍历到的节点都是当前节点的祖先节点
 * O(n)dfs O(50)枚举所有情况，总复杂度O(50n)
 */
const int MAXV=51;
bool prime[MAXV][MAXV];
bool already_build=false;
void build_prime() {
    if (already_build) {
        return;
    }
    already_build=true;
    memset(prime,false,sizeof(prime));
    for (int i=1;i<MAXV;i++) {
        for (int j=i;j<MAXV;j++) {
            if (__gcd(i,j)==1) {
                prime[i][j]=true;
                prime[j][i]=true;
            }
        }
    }
}
const int MINF=0xc0c0c0c0;
int dep[MAXV];
const int MAXN=1e5;
int vis[MAXN];
class Solution {
    vector<int> ans;
    vector<vector<int>> edg;
    vector<int> path;
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        build_prime();
        memset(dep,0xc0,sizeof(int)*MAXV);
        int sz=nums.size();
        memset(vis,0,sizeof(int)*sz);
        ans=vector<int>(sz,-1);
        edg=vector<vector<int>>(sz);
        for (vector<int> &i:edges) {
            int a=i.at(0),b=i.at(1);
            edg.at(a).push_back(b);
            edg.at(b).push_back(a);
        }
        path.clear();
        path.reserve(MAXN);
        dfs(nums,0,0);
        return ans;
    }
    void dfs(vector<int> &nums,int idx,int curDep) {
        vis[idx]=1;
        int val=nums.at(idx);
        int preDep=dep[val];
        int mxDep=-1;
        int resIdx=-1;
        for (int i=1;i<MAXV;i++) {
            if (prime[val][i] && dep[i]>mxDep) {
                mxDep=dep[i];
                resIdx=path.at(mxDep);
            }
        }
        if (resIdx!=-1) {
            ans.at(idx)=resIdx;
        }
        dep[val]=curDep;
        path.push_back(idx);
        for (int i:edg.at(idx)) {
            if (vis[i]==0) {
                dfs(nums,i,curDep+1);
            }
        }
        dep[val]=preDep;
        path.pop_back();
    }
};
