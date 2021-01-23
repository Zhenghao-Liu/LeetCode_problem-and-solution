class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int size=A.size();
        vector<bool> ans(size);
        int num=0;
        for (int i=0;i<size;i++) {
            num<<=1;
            num+=A.at(i);
            num%=5;
            if (num==0) {
                ans.at(i)=true;
            }
        }
        return ans;
    }
};
