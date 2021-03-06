class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool flag1=true,flag2=true;
        int sz=A.size();
        for (int i=1;i<sz;i++) {
            if (flag1 && A.at(i-1)>A.at(i)) {
                flag1=false;
            }
            if (flag2 && A.at(i-1)<A.at(i)) {
                flag2=false;
            }
            if (!flag1 && !flag2) {
                return false;
            }
        }
        return flag1 || flag2;
    }
};
