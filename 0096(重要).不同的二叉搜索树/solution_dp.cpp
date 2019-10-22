/*
* 动态规划，看题解明白分析过程
* 设n个节点的二叉搜索树个数为G(n)
* 设以i为头结点的二叉搜索树个数为f(i)
* G(n)=f(1)+f(2)+...+f(n)
* 对于以i为头节点的二叉搜索树
* 其左子树上节点为[1,2,...,i-1]共(i-1)个
* 其右子树上节点为[i+1,i+2,...,n]共(n-i)个
* 得f(i)=G(i-1)*G(n-i)
* 得G(n)=G(0)*G(n-1)+G(1)*G(n-2)+...+G(n-1)*G(0)
* 注意这里的n，对于不同的n，G(n-i)是不同的结果所以要重新算
*/
class Solution {
public:
    int numTrees(int n) {
        if (n==0)
            return 1;
        vector<int> answer(n+1,0);
        answer.at(0)=1;
        int temporary;
        for (int i=1;i<=n;++i)
            for (int j=0;j<i;++j)
                answer.at(i)=answer.at(i)+answer.at(j)*answer.at(i-j-1);       
        return answer.at(n);
    }
};
