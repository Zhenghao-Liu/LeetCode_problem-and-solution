class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int sz=s.size();
        if (s.back()=='1') {
            return false;
        }
        vector<int> vec(sz,0);
        vec.at(0)=1;
        vector<int> pre(sz+1,0);
        for (int i=0;i<minJump;i++) {
            pre.at(i+1)=pre.at(i)+vec.at(i);
        }
        for (int i=minJump;i<sz;i++) {
            int l=max(0,i-maxJump),r=i-minJump;
            if (s.at(i)=='0' && r>=0 && pre.at(r+1)-pre.at(l)>=1) {
                vec.at(i)=1;
            }
            pre.at(i+1)=pre.at(i)+vec.at(i);
        }
        return vec.back()==1;
    }
};