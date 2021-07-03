// 移到后面的操作可以等价于，在s后面加一个s，然后滑窗移动
// 判断整体是否相等因为是滑窗，所以只用判断入与出即可
class Solution {
public:
    int minFlips(string s) {
        int sz=s.size();
        s+=s;
        string a;
        int flag=0;
        for (int i=0;i<sz*2;i++) {
            a+=flag==0 ? '0' : '1';
            flag^=1;
        }
        int ans=sz;
        int res=0;
        for (int i=0;i<sz;i++) {
            if (s.at(i)!=a.at(i)) {
                res++;
            }
        }
        ans=min(res,sz-res);
        for (int i=sz;i<sz*2;i++) {
            int back=s.at(i)==a.at(i) ? 0 : 1;
            int front=s.at(i-sz)==a.at(i-sz) ? 0 : 1;
            res+=back-front;
            ans=min(ans,min(res,sz-res));
        }
        return ans;
    }
};