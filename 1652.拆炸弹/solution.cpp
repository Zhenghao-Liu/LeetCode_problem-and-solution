class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> ans(n);
        if (k==0)
            return ans;
        for (int i=0;i<n;++i)
            code.push_back(code.at(i));
        int st,ed;
        if (k>0)
        {
            st=0;
            ed=n;
        }
        else
        {
            st=n;
            ed=2*n;
        }
        int idx=0;
        for (int i=st;i<ed;++i)
        {
            int s=0;
            if (k>0)
                for (int j=i+1;j-i<=k;++j)
                    s+=code.at(j);
            else
                for (int j=i+k;j<i;++j)
                    s+=code.at(j);
            ans.at(idx)=s;
            ++idx;
        }
        return ans;
    }
};
