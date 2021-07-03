class Solution {
public:
    string maxValue(string n, int x) {
        int sz=n.size();
        char xx=x+'0';
        if (n.at(0)=='-') {
            int i=1;
            for (i=1;i<sz;i++) {
                if (n.at(i)>xx) {
                    break;
                }
            }
            n.insert(n.begin()+i,xx);
            return n;
        } else {
            int i=0;
            for (i=0;i<sz;i++) {
                if (n.at(i)<xx) {
                    break;
                }
            }
            n.insert(n.begin()+i,xx);
            return n;
        }
        return "";
    }
};