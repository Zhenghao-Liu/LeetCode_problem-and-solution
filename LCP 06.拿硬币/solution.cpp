class Solution {
public:
    int minCount(vector<int>& coins) {
        int ans=0;
        for (int &i:coins)
            if (i%2==0)
                ans+=i/2;
            else
                ans+=i/2+1;
        return ans;
    }
};
