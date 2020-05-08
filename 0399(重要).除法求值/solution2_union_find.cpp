/*
* union find || disjoint set find || 并查集
* [B站讲解1](https://www.bilibili.com/video/BV13t411v7Fs/)
* [B站讲解2](https://www.bilibili.com/video/BV1BJ41137qp/)
*/
/*
* 对于所有节点建好并查集
* 设每条边的权值即为该节点除父节点的商
* 在find时候路径压缩，记得更新权值和父节点
* 倘若无对应节点，或两节点不在一集合时，返回-1
* 若联通，则a/b返回的是 a对代表元(最顶的根节点)的商x 与 b对代表元(最顶的根节点)的商y
  相除即结果 即a/根=x b/根=y a/b=a/根/(b/根)=x/y
*/
class Solution {
    unordered_map<string,string> parent;
    //边的权值：即该节点 除 父节点 的 商
    unordered_map<string,double> quotient;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //初始化图
        initialise(equations);
        int size=values.size();
        //导入边和权值
        for (int i=0;i<size;++i)
            union_vertices(equations.at(i).at(0),equations.at(i).at(1),values.at(i));
        vector<double> ans;
        for (vector<string> &i:queries)
        {
            if (parent.find(i.at(0))==parent.end() || parent.find(i.at(1))==parent.end())
                ans.push_back(-1.0);
            else if (i.at(0)==i.at(1))
                ans.push_back(1.0);
            else
            {
                //不仅找了根节点，还进行了路径压缩
                string A_root=find_root(i.at(0));
                string B_root=find_root(i.at(1));
                //倘若两个不在一个集合，即现有方程无法求解
                if (A_root!=B_root)
                    ans.push_back(-1);
                //在一个集合
                //a/b返回的是 a对代表元(最顶的根节点)的商x 与 b对代表元(最顶的根节点)的商y
                //相除即结果 即a/根=x b/根=y a/b=a/根/(b/根)=x/y
                //又因为前面路径压缩了，所以对父亲节点的商就是对根节点的商
                else
                    ans.push_back(quotient.at(i.at(0))/quotient.at(i.at(1)));
            }
        }
        return ans;
    }
    void initialise(vector<vector<string>> & equations)
    {
        parent.clear();
        quotient.clear();
        for (vector<string> &i:equations)
            for (int j=0;j<2;++j)
                if (parent.find(i.at(j))==parent.end())
                {
                    //初始化所有单个节点的父节点都是自己
                    parent.insert({i.at(j),i.at(j)});
                    quotient.insert({i.at(j),1.0});
                }
    }
    string find_root(string &s)
    {
        if (parent.at(s)!=s)
        {
            string root=find_root(parent.at(s));
            //路径压缩:在回溯过程让刚刚搜索过的节点，父节点直接指向根节点
            quotient.at(s)*=quotient.at(parent.at(s));
            parent.at(s)=root;
            //优化效率还有按秩合并，本题不适合
            return root;
        }
        return s;
    }
    //A/B=values
    void union_vertices(string &A,string &B,double values)
    {
        string A_root=find_root(A);
        string B_root=find_root(B);
        //A和B已经是存在一个集合了
        //即可能公式有a/b=x b/a=1/x这种重复的方程时候就不会重新构建
        //这里也可以用于检测无向图有无环：有环即两个节点已经在一个集合中
        if (A_root==B_root)
            return;
        //前面已经进行了路径压缩，这里因为优化外加权值麻烦很多原本parent[A_root]=B_root即可
        /*
        * 做一个数学推导，因为前面已经做过路径压缩
        * A->C 权值为x 即A的父(根)节点是C且A/C=x
        * B->D 权值为y 即C的父(根)节点时B且B/D=y
        * 现在多了一个新方程即A/B=values
        * union是将两个集合的根节点连起来，我们这里设C指向D
        * 即C的父节点设为D，我们要求C/D=?
        * 即C/D=y/x*(A/B)=y/x*values
        */
        parent.at(A_root)=B_root;
        quotient.at(A_root)=values*quotient.at(B)/quotient.at(A);
    }
};
