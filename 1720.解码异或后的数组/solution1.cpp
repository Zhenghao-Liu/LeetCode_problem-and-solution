class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans{first};
        for (int i:encoded) {
            int res=0;
            int a=ans.back();
            int step=0;
            while (i>0 || a>0) {
                int aa= (a&1)!=0 ? 1 : 0;
                int ii= (i&1)!=0 ? 1 : 0;
                if (aa==ii) {
                    res|=0;
                } else {
                    res|=1<<step;
                }
                step++;
                i>>=1;
                a>>=1;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
