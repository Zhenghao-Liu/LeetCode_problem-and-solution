//线段树模板
typedef long long ll;
const int N=1e5+1;
constexpr int MAXN=N*4;
int tree[MAXN];
class Solution {
    int mod=1e9+7;
public:
    int createSortedArray(vector<int>& instructions) {
        memset(tree,0,sizeof(tree));
        ll ans=0;
        for (int i:instructions)
        {
            int less=get_sum(0,0,N-1,0,i-1);
            int greater=get_sum(0,0,N-1,i+1,N-1);
            ans+=min(less,greater);
            ans%=mod;
            update_tree(0,0,N-1,i);
        }
        return ans;
    }

    //自增1
    void update_tree(int node,int begin,int end,int i)
    {
        if (begin==i && end==i)
        {
            ++tree[node];
            return;
        }
        int mid=(begin+end)/2;
        int left_node=node*2+1;
        int right_node=node*2+2;
        if (i<=mid)
            update_tree(left_node,begin,mid,i);
        //if (i>mid)
        else
            update_tree(right_node,mid+1,end,i);
        tree[node]=tree[left_node]+tree[right_node];        
    }

    int get_sum(int node,int begin,int end,int i,int j)
    {
        if (j<begin || i>end)
            return 0;
        if (begin>=i && end<=j)
            return tree[node];
        int mid=(begin+end)/2;
        int left_node=node*2+1;
        int right_node=node*2+2;
        return get_sum(left_node,begin,mid,i,j)+get_sum(right_node,mid+1,end,i,j);
    }
};
