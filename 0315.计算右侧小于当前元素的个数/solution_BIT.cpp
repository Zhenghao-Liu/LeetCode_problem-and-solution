/*
* 首先[树状数组BIT](https://www.bilibili.com/video/BV1pE41197Qj/)
* 可以从右往左逆序方式遍历nums
  并将nums[i]放入对应的桶中，
  eg[5 2 6 1 1]
  因为最大值是6，开一个长度为7的桶数组(有一个无用索引0，这里写下标是1开始的)
  从右往左遍历到1，则++数组[1]，即数组[1 0 0 0 0 0]
  从右往左遍历到1，则++数组[1]，即数组[2 0 0 0 0 0]
  从右往左遍历到6，则++数组[6]，即数组[2 0 0 0 0 1]
  从右往左遍历到2，则++数组[2]，即数组[2 1 0 0 0 1]
  从右往左遍历到5，则++数组[5]，即数组[2 1 0 0 1 1]
* 这样通过数组从右往左遍历的过程，因为桶的设计是[1]~[max_element(nums)]
  则遍历到数字i时，需要++桶数组[i]，
  那么<i的桶统计了对于数字i在nums中右边小于数字i的个数的统计
  那么只需要前缀和的方式即可求出当前右侧小于当前数字的个数
  eg[5 2 6 1 1]
  从右往左遍历到5，则++数组[5]，即数组[2 1 0 0 1 1]
  那么小于5的个数就是数组[1]~数组[4]的区间和，即2+1+0+0=3
* 前缀和+要单点修改，树状数组就可以派上用场
* 但是有个地方注意，上面设置桶是按nums最大值来设置桶数组的长度
  但万一nums不是全为正数的数组，或者万一nums最大值是一个很大的数
  直接按照值=index的方式设置桶是不行的，一会mle，二会有很多空桶没有作用，且增加复杂度
* 所以采用离散化数组，即按数值从小到大来映射桶
  即[5 2 6 1 1]有用的数值只有[1 2 5 6]可以设置映射
  f[1]=1 f[2]=2 f[5]=3 f[6]=4即f[nums中数值]=BIT数组的索引index
  这样优化空间且不用担心负数的情况
*/
class Solution {
    //key存nums[i]值，value是对应的BIT中BIT[index]的index
    unordered_map<int,int> f;
    vector<int> BIT;
    int n;
public:
    vector<int> countSmaller(vector<int>& nums) {
        int nums_size=nums.size();
        get_f(nums);
        BIT=vector<int>(n+1,0);
        vector<int> ans;
        ans.reserve(nums_size);
        for (int i=nums_size-1;i>=0;--i)
        {
            int add_x=f.at(nums.at(i));
            add(add_x,1);
            int ask_x=add_x-1;
            ans.push_back(ask(ask_x));
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void get_f(vector<int> &nums)
    {
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        auto end=unique(temp.begin(),temp.end());
        int index=0;
        for (auto p=temp.begin();p!=end;++p)
        {
            ++index;
            f[*p]=index;
        }
        n=index;
    }
    int lowbit(int x)
    {
        return x&(-x);
    }
    void add(int x,int k)
    {
        for (;x<=n;x+=lowbit(x))
            BIT.at(x)+=k;
    }
    int ask(int x)
    {
        int ans=0;
        for (;x>0;x-=lowbit(x))
            ans+=BIT.at(x);
        return ans;
    }
};
