class Solution {
public:
    bool canChoose(vector<vector<int>>& gro, vector<int>& nums) {
        int szA=gro.size();
        int szB=nums.size();
        int i=0,j=0;
        while (i<szA && j<szB) {
            int sz=gro.at(i).size();
            int ii=0,jj=j;
            while (ii<sz && jj<szB) {
                if (gro.at(i).at(ii)!=nums.at(jj)) {
                    break;
                } else {
                    ii++;
                    jj++;
                }
            }
            if (ii==sz) {
                j=jj;
                i++;
            } else {
                j++;
            }
        }
        return i==szA;
    }
};
