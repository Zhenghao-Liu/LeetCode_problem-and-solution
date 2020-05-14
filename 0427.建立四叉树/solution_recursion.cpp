/**
* 题目有点难看懂
* 其实就是一个正方形矩阵，把他四等分，即对应四个叶节点
* 倘若所有的节点的值都是一个值(0/1)，则代表是一个叶子节点
* 倘若块中节点的值不一，则表明该块不是叶子节点，所以应该递归该块
* 数据范围很小直接暴力就好
*/
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid,0,0,grid.size());
    }
    Node * dfs(vector<vector<int>> &grid,int x,int y,int length)
    {
        int cur=grid.at(x).at(y);
        for (int i=x;i<x+length;++i)
            for (int j=y;j<y+length;++j)
                if (grid.at(i).at(j)!=cur)
                {
                    cur=-1;
                    break;
                }
        if (cur==-1)
            return new Node(true,false,dfs(grid,x,y,length/2),dfs(grid,x,y+length/2,length/2),dfs(grid,x+length/2,y,length/2),dfs(grid,x+length/2,y+length/2,length/2));
        else
            return new Node(cur==1,true);
    }
};
