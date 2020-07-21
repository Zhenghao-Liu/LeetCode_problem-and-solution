/*
* 显然与运算是一个递减的函数，因为1能变成1/0，而0只能变成0
* 那么固定好左边界，右边界增大，因为递减函数，与运算结果会越来越小，那么有序就想到了二分
* |func(arr, l, r) - target|尽可能的小
  现在固定好左边界，要找的就是func(arr, l, r)>=target的最小值
                         和func(arr, l, r)<target的最大值
  这样就能保证绝对值尽可能小，通过二分找func，也可以用倍增
* 怎么求func呢，就要用到线段树了，这里BIT不行因为与运算无法求逆
* 此外，两个相同的元素相与还是本身，所以一开始可以用unique进行处理掉连续相同的情况
* 复杂度O(N*logN*logN)
*/
//线段树
const int MAXN=262143;
class NumArray {
    int tree[MAXN];
    int nums_size;
public:
    NumArray(vector<int>& nums,int size) {
        nums_size=size;
        //二叉树第i层最多有2^(i-1)个节点
        //二叉树有i层，则总共最多有2^i-1个节点
        //这里是假设所有nums的单个数据都存在最后一层，即最大可能需要存储的个数
        build_tree(nums,0,0,nums_size-1);
    }
    
    void build_tree(vector<int>& nums,int node,int begin,int end)
    {
        if (begin==end)
        {
            tree[node]=nums.at(begin);
            return;
        }
        int mid=(begin+end)/2;
        int left_node=node*2+1;
        int right_node=node*2+2;
        build_tree(nums,left_node,begin,mid);
        build_tree(nums,right_node,mid+1,end);
        tree[node]=tree[left_node]&tree[right_node];
    }

    int sumRange(int i, int j) {
        return get_sum(0,0,nums_size-1,i,j);
    }

    int get_sum(int node,int begin,int end,int i,int j)
    {
        if (j<begin || i>end)
            return -1;
        if (begin>=i && end<=j)
            return tree[node];
        int mid=(begin+end)/2;
        int left_node=node*2+1;
        int right_node=node*2+2;
        return get_sum(left_node,begin,mid,i,j)&get_sum(right_node,mid+1,end,i,j);
    }
};


class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        auto p=unique(arr.begin(),arr.end());
        int arr_size=p-arr.begin();
        NumArray segment_t(arr,arr_size);
        int ans=INT_MAX;
        for (int i=0;i<arr_size;++i)
        {
            //二分
            int l=i,r=arr_size-1;
            while (l<r)
            {
                int mid=l+(r-l+1)/2;
                int value=segment_t.sumRange(i,mid);
                if (value>=target)
                    l=mid;
                else
                    r=mid-1;
            }
            ans=min(ans,abs(segment_t.sumRange(i,l)-target));
            if (l+1<arr_size)
                ans=min(ans,abs(segment_t.sumRange(i,l+1)-target));

            //倍增
            // int r=i;
            // for (int k=20;k>=0;--k)
            // {
            //     int cur=i+(1<<k);
            //     if (cur>=arr_size)
            //         continue;
            //     if (segment_t.sumRange(i,cur)>=target)
            //         r=cur;
            // }
            // ans=min(ans,abs(target-segment_t.sumRange(i,r)));
            // if (r+1<arr_size)
            //     ans=min(ans,abs(segment_t.sumRange(i,r+1)-target));
        }
        return ans;
    }
};
