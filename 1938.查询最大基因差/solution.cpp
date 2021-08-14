// 离线查询+字典树
// dfs去遍历，做到离线查询，但记得移出字典树
typedef pair<int,int> pii;
const int MAXV=17;
class Trie {
public:
    Trie* arc[2]={NULL};
    /** Initialize your data structure here. */
    Trie() {
        arc[0]=arc[1]=NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(int word) {
        Trie* p=this;
        for (int j=MAXV;j>=0;j--)
        {
            int nxt=((1<<j)&word)!=0 ? 1 : 0;
            if (p->arc[nxt]==NULL)
                p->arc[nxt]=new Trie();
            p=p->arc[nxt];
        }
    }
    
    void erase(int word) {
        stack<pair<Trie*,int>> sta;
        Trie* p=this;
        int nxt;
        for (int j=MAXV;j>=0;j--) {
            nxt=((1<<j)&word)!=0 ? 1 : 0;
            sta.push({p,nxt});
            p=p->arc[nxt];
        }
        while (!sta.empty()) {
            // delete p;
            p=sta.top().first;
            nxt=sta.top().second;
            sta.pop();
            p->arc[nxt]=NULL;
            if (p->arc[nxt^1]!=NULL) {
                break;
            }
        }
    }

    int helper(int tar) {
        int ans=0;
        Trie* p=this;
        for (int j=MAXV;j>=0;j--) {
            int cur=((1<<j)&tar)!=0 ? 1 :0;
            int nxt=1^cur;
            if (p->arc[nxt]==NULL) {
                nxt^=1;
            }
            ans|=nxt<<j;
            p=p->arc[nxt];
        }
        return ans^tar;
    }
};
class Solution {
    Trie *root;
    vector<vector<int>> edge;
    vector<vector<pii>>offline;
    int sz,rootVal;
    vector<int> ans;
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        root=new Trie();
        sz=parents.size();
        edge=vector<vector<int>>(sz);
        for (int i=0;i<sz;i++) {
            int ii=parents.at(i);
            if (ii==-1) {
                rootVal=i;
                continue;
            }
            edge.at(ii).push_back(i);
        }
        offline=vector<vector<pii>>(sz);
        int qsz=queries.size();
        for (int i=0;i<qsz;i++) {
            int node=queries.at(i).at(0);
            int val=queries.at(i).at(1);
            offline.at(node).push_back({val,i});
        }
        ans=vector<int>(qsz);
        dfs(rootVal);
        return ans;
    }

    void dfs(int nodeVal) {
        root->insert(nodeVal);
        for (auto [tar,idx]:offline.at(nodeVal)) {
            int res=root->helper(tar);
            ans.at(idx)=res;
        }
        for (int nxt:edge.at(nodeVal)) {
            dfs(nxt);
        }
        root->erase(nodeVal);
    }
};