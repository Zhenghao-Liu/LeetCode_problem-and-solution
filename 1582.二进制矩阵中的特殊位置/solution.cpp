//暴力n^3
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat.at(0).size();
        int ans=0;
        for (int i=0;i<r;++i)
            for (int j=0;j<c;++j)
                if (mat.at(i).at(j)==1)
                {
                    bool b=false;
                    for (int ii=0;ii<r;++ii)
                        if (ii!=i && mat.at(ii).at(j)==1)
                        {
                            b=true;
                            break;
                        }
                    if (b)
                        continue;
                    for (int jj=0;jj<c;++jj)
                        if (jj!=j && mat.at(i).at(jj)==1)
                        {
                            b=true;
                            break;
                        }
                    if (b)
                        continue;
                    ++ans;
                }
        return ans;
    }
};
