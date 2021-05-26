class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back()=='1') {
            return false;
        }
        int sz=s.size();
        vector<int> vec;
        vec.reserve(sz);
        vec.push_back(0);
        for (int i=1;i<sz;i++) {
            if (s.at(i)=='1') {
                continue;
            }
            int l=i-maxJump,r=i-minJump;
            auto p=lower_bound(vec.begin(),vec.end(),l);
            if (p!=vec.end() && (*p)<=r) {
                vec.push_back(i);
            }
        }
        return vec.back()==sz-1;
    }
};