class NumArray {
    vector<int> tree;
    int nums_size;
public:
    NumArray(vector<int>& nums) {
        nums_size=nums.size();
        if (nums_size==0)
            return;
        //二叉树第i层最多有2^(i-1)个节点
        //二叉树有i层，则总共最多有2^i-1个节点
        //这里是假设所有nums的单个数据都存在最后一层，即最大可能需要存储的个数
        int temp=2,i=2;
        for (;temp<nums_size;++i)
            temp=temp<<1;
        tree=vector<int>(pow(2,i)-1,0);
        build_tree(nums,0,0,nums_size-1);
    }
    
    void build_tree(vector<int>& nums,int node,int begin,int end)
    {
        if (begin==end)
        {
            tree.at(node)=nums.at(begin);
            return;
        }
        int mid=(begin+end)/2;
        int left_node=node*2+1;
        int right_node=node*2+2;
        build_tree(nums,left_node,begin,mid);
        build_tree(nums,right_node,mid+1,end);
        tree.at(node)=tree.at(left_node)+tree.at(right_node);
    }

    void update(int i, int val) {
        update_tree(0,0,nums_size-1,i,val);
    }
    
    void update_tree(int node,int begin,int end,int i,int val)
    {
        if (begin==i && end==i)
        {
            tree.at(node)=val;
            return;
        }
        int mid=(begin+end)/2;
        int left_node=node*2+1;
        int right_node=node*2+2;
        if (i<=mid)
            update_tree(left_node,begin,mid,i,val);
        //if (i>mid)
        else
            update_tree(right_node,mid+1,end,i,val);
        tree.at(node)=tree.at(left_node)+tree.at(right_node);        
    }

    int sumRange(int i, int j) {
        return get_sum(0,0,nums_size-1,i,j);
    }

    int get_sum(int node,int begin,int end,int i,int j)
    {
        if (j<begin || i>end)
            return 0;
        if (begin>=i && end<=j)
            return tree.at(node);
        int mid=(begin+end)/2;
        int left_node=node*2+1;
        int right_node=node*2+2;
        return get_sum(left_node,begin,mid,i,j)+get_sum(right_node,mid+1,end,i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
