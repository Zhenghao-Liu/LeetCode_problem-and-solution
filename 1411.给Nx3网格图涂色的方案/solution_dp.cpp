class Solution {
public:
    int numOfWays(int n) {
        long long ABA=6,ABC=6,helper=1e9+7;
        for (int i=1;i<n;++i)
        {
            long new_ABA=(3*ABA+2*ABC)%helper;
            long new_ABC=(2*ABA+2*ABC)%helper;
            ABA=new_ABA;
            ABC=new_ABC;
        }
        return (ABA+ABC)%helper;
    }
};
