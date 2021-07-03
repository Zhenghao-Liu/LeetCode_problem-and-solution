class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int sz=nums.size();
        if (sz==2) {
            return true;
        }
        vector<int> vec;
        vec.reserve(sz-1);
        for (int &i:nums) {
            int ii=i;
            i=0;
            vec.clear();
            for (int j:nums) {
                if (j!=0) {
                    vec.push_back(j);
                }
            }
            bool ans=true;
            for (int k=1;k<sz-1;k++) {
                if (vec.at(k-1)>=vec.at(k)) {
                    ans=false;
                }
            }
            if (ans) {
                return true;
            }
            i=ii;
        }
        return false;
    }
};