/*
* 把所有字典序数字画成一个以根为0的十叉树
  前序遍历即是字典序
* 那么要做的就是求当前节点pos为根节点的子树它一共包含了多少个节点
  即通过get_subtree_nodes，即难点
  用start表明当前计算层的起点，
  有两种可能，要么该层满节点即十叉树十个节点，那末尾就是end-1
  要么该层没有满，那么末尾就是n
  求当前层节点有多少个，即末尾减-start+1
* 如果当前子树的节点个数小于k，说明不在这颗子树，在他的右边，所以向右移动
  如果当前子树的节点个数大于k，表明在目标在这颗子树里面，向下移动
* 每次都要对k进行减操作，因为k的意思是相对于以pos为根节点的子树的前序遍历中的第几个节点
* 所以一开始偷懒将起始点设为了1，亦可以循环一次来实现
*/
class Solution {
public:
    int findKthNumber(int n, int k) {
        int pos=1;
        --k;
        while (k>0)
        {
            int subtree_nodes=get_subtree_nodes(n,pos);
            //向右移动
            if (k>=subtree_nodes)
            {
                k-=subtree_nodes;
                ++pos;
            }
            //向下移动
            else
            {
                --k;
                pos*=10;
            }
        }
        return pos;
    }
    int get_subtree_nodes(long long n,long long start)
    {
        int count=0;
        for (long long end=start+1;start<=n;start*=10,end*=10)
            count+=min(end-1,n)-start+1;
        return count;
    }
};
