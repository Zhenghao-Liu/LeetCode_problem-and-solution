//注意是无向图
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& _edges, string labels) {
        vector<int> ans(n,1);
        vector<vector<int>> edges(n);
        for (vector<int> &i:_edges)
        {
            edges.at(i.at(0)).push_back(i.at(1));
            edges.at(i.at(1)).push_back(i.at(0));
        }
        vector<bool> visit(n,false);
        visit.at(0)=true;
        vector<int> v(26,0);
        dfs(0,ans,edges,labels,v,visit);
        return ans;
    }
    void dfs(int node,vector<int> &ans,vector<vector<int>> &edges,string &labels,vector<int> &v,vector<bool> &visit)
    {
        if (!edges.at(node).empty())
        {
            vector<int> vv(26,0);
            for (int i:edges.at(node))
                if (!visit.at(i))
                {
                    visit.at(i)=true;
                    fill(vv.begin(),vv.end(),0);
                    dfs(i,ans,edges,labels,vv,visit);
                    for (int j=0;j<26;++j)
                        if (vv.at(j)!=0)
                            v.at(j)+=vv.at(j);
                }
        }
        int index=labels.at(node)-'a';
        ++v.at(index);
        ans.at(node)=v.at(index);
    }
};
