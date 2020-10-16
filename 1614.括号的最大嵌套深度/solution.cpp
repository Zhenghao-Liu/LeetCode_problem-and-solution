class Solution {
public:
    int maxDepth(string s) {
        int left=0;
        int ans=0;
        for (char i:s)
        {
            if (i=='(')
            {
                ++left;
                ans=max(ans,left);
            }
            else if (i==')')
                --left;
        }
        return ans;
    }
};
