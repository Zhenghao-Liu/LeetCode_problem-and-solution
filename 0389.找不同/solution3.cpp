class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans=0;
        for (char &i:t)
            ans+=i;
        for (char &i:s)
            ans-=i;
        return ans;
    }
};
