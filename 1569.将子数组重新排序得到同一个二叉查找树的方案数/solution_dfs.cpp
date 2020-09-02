/*
* $$C_{left+right}^{left}*dfs(left)*dfs(right)$$
* nums[0]必然是根节点
  在后面的序列，可以根据与nums[0]比较大小，分为左子树和右子树
  只要左子树中相对顺序一定，右子树中相对顺序一定，就能保证bst一定
  剩下就是求left+right的顺序？
  $$C_{left+right}^{left}$$
  可以理解成一共有 x 个坑，先选出一部分放 left，剩下的放 right
*/
typedef long long ll;
const int MAXN=1001;
ll mod=1e9+7;
//$C_{n}^{m}$即comb[n][m]
ll comb[MAXN][MAXN];
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int nums_size=nums.size();
        build_comb(nums_size);
        //最后-1是因为除去本身nums序列
        return (dfs(nums)-1+mod)%mod;
    }
    void build_comb(int limit)
    {
        for (int n=1;n<=limit;++n)
            for (int m=0;m<=n;++m)
            {
                if (m==n || m==0)
                    comb[n][m]=1;
                else
                    comb[n][m]=(comb[n-1][m]%mod+comb[n-1][m-1]%mod)%mod;
            }
    }
    long long dfs(vector<int> &nums)
    {
        int nums_size=nums.size();
        if (nums_size<=1)
            return 1;
        vector<int> left;
        left.reserve(nums_size);
        vector<int> right;
        right.reserve(nums_size);
        for (int i=1;i<nums_size;++i)
            if (nums.at(i)>nums.at(0))
                right.push_back(nums.at(i));
            else
                left.push_back(nums.at(i));
        int left_size=left.size();
        int right_size=right.size();
        return (comb[left_size+right_size][left_size]%mod)*(dfs(left)%mod)%mod*(dfs(right)%mod)%mod;
    }
};
