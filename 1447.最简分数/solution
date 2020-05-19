class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i=1;i<=n-1;++i)
            for (int j=i+1;j<=n;++j)
            {
                int helper=gcd(i,j);
                if (helper==1)
                {
                    ans.push_back(to_string(i)+'/'+to_string(j));
                }
            }
        return ans;
    }
};
