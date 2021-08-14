typedef long long ll;
ll mod=INT_MAX;
struct Node {
    string val;
    string has;
    vector<Node *> son;
    Node(string x) : val(x) {}
};
class Solution {
    unordered_map<string,int> ump;
    vector<vector<string>> ans;
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        sort(paths.begin(),paths.end());
        Node *root=new Node("");
        for (vector<string> &i:paths) {
            dfs(root,i,0);
        }
        ump.clear();
        dfshash(root);
        ans.clear();
        vector<string> path;
        for (Node *i:root->son) {
            helper(i,path);
        }
        return ans;
    }
    void helper(Node *cur,vector<string> &path) {
        if (ump[cur->has]>1 && cur->has!="") {
            return;
        }
        path.push_back(cur->val);
        ans.push_back(path);
        for (Node *i:cur->son) {
            helper(i,path);
        }
        path.pop_back();
    }
    string dfshash(Node *cur) {
        string has;
        for (Node *i:cur->son) {
            string nxt=dfshash(i);
            has+=nxt+"+";
        }
        if (has.size()>1) {
            has.pop_back();
        }
        cur->has=has;
        ump[cur->has]++;
        return "("+cur->val+")"+has;
    }
    void dfs(Node *cur,vector<string> &vec,int idx) {
        if (idx==vec.size()) {
            return;
        }
        if (cur->son.empty() || cur->son.back()->val!=vec.at(idx)) {
            cur->son.push_back(new Node(vec.at(idx)));
        }
        dfs(cur->son.back(),vec,idx+1);
    }
};