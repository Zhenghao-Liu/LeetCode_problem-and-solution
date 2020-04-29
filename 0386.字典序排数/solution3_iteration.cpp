class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int num=1;
        for (int i=0;i<n;++i)
        {
            ans.at(i)=num;
            if (num*10<=n)
                num*=10;
            else
            {
                if (num==n)
                    num/=10;
                ++num;
                while (num%10==0)
                    num/=10;
            }
        }
        return ans;
    }
};
