class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int size=A.size();
        if (size<3)
            return false;
        int i=0;
        bool flag1=false;
        for (i=0;i<size-1;++i)
            if (A.at(i)>=A.at(i+1))
                break;
            else
                flag1=true;
        bool flag2=false;
        for (;i<size-1;++i)
            if (A.at(i)<=A.at(i+1))
                break;
            else
                flag2=true;
        return i==size-1 && flag1 && flag2;
    }
};
