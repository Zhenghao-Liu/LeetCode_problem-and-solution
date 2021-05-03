typedef long long ll;
class Solution {
    string s;
    int sz;
public:
    bool splitString(string s) {
        this->s=s;
        sz=s.size();
        ll num=0;
        bool ans=false;
        for (int i=0;i<sz-1;i++) {
            num=num*10+(s.at(i)-'0');
            if (num>9999999999) {
                break;
            }
            ans=dfs(i+1,num);
            if (ans) {
                return true;
            }
        }
        return false;
    }
    bool dfs(int st,ll pre) {
        if (st==sz) {
            return true;
        }
        ll num=0;
        for (int i=st;i<sz;i++) {
            num=num*10+(s.at(i)-'0');
            if (num>pre-1) {
                return false;
            }
            if (num==pre-1 && dfs(i+1,num)) {
                return true;
            }
        }
        return false;
    }
};