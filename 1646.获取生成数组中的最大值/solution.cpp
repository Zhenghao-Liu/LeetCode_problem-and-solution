class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n<=1)
            return n;
        vector<int> v(n+1);
        v.at(0)=0;
        v.at(1)=1;
        int ans=1;
        for (int i=2;i<=n;++i)
        {
            if (i%2==0)
                v.at(i)=v.at(i/2);
            else
                v.at(i)=v.at(i/2)+v.at((i+1)/2);
            ans=max(ans,v.at(i));
        }
        return ans;
    }
};
