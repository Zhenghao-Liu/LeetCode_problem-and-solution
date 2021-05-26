class Solution {
    string ans;
    int sz;
public:
    string reverseParentheses(string s) {
        ans.clear();
        sz=s.size();
        dfs(s,0);
        return ans;
    }
    int dfs(string &s,int st) {
        for (int i=st;i<sz;i++) {
            if (s.at(i)==')') {
                return i;
            } else if (s.at(i)=='(') {
                int cur=ans.size();
                int ed=dfs(s,i+1);
                reverse(ans.begin()+cur,ans.end());
                i=ed;
            } else {
                ans+=s.at(i);
            }
        }
        return sz;
    }
};