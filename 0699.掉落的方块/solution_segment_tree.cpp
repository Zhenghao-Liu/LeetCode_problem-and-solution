//先离散化后，线段树区域增加，线段树求区间最大值
class SE_TREE {
    vector<int> tree;
    int nums_size;
public:
    SE_TREE(int size) {
        nums_size=size;
        tree=vector<int>(nums_size*4,0);
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
        tree.at(node)=max(tree.at(left_node),tree.at(right_node));        
    }

    int maxRange(int i, int j) {
        return get_max(0,0,nums_size-1,i,j);
    }

    int get_max(int node,int begin,int end,int i,int j)
    {
        if (j<begin || i>end)
            return 0;
        if (begin>=i && end<=j)
            return tree.at(node);
        int mid=(begin+end)/2;
        int left_node=node*2+1;
        int right_node=node*2+2;
        return max(get_max(left_node,begin,mid,i,j),get_max(right_node,mid+1,end,i,j));
    }
};
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int positions_size=positions.size();
        vector<int> pos;
        pos.reserve(positions_size*2);
        for (vector<int> &i:positions)
        {
            pos.push_back(i.at(0));
            pos.push_back(i.at(0)+i.at(1)-1);
        }
        sort(pos.begin(),pos.end());
        int unique_end=unique(pos.begin(),pos.end())-pos.begin();
        int index=0;
        unordered_map<int,int> pos_index;
        for (int i=0;i<unique_end;++i)
        {
            pos_index[pos.at(i)]=index;
            ++index;
        }
        vector<int> ans;
        ans.reserve(positions_size);
        SE_TREE se_tree(unique_end);
        for (vector<int> &i:positions)
        {
            int begin=pos_index.at(i.at(0));
            int end=pos_index.at(i.at(0)+i.at(1)-1);
            int cur=se_tree.maxRange(begin,end);
            for (int j=begin;j<=end;++j)
                se_tree.update(j,cur+i.at(1));
            ans.push_back(se_tree.maxRange(0,unique_end-1));
        }
        return ans;
    }
};
