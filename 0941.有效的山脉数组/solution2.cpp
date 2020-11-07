class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int size=A.size();
        if (size<3)
            return false;
        int l=0,r=size-1;
        while (l<r && A.at(l)<A.at(l+1))
            ++l;
        while (l<r && A.at(r-1)>A.at(r))
            --r;
        return l==r && l!=0 && r!=size-1;
    }
};
