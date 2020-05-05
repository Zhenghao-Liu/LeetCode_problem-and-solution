class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m=INT_MIN;
        for (int &i:candies)
            m=max(i,m);
        int candies_size=candies.size();
        vector<bool> ans(candies_size,false);
        for (int i=0;i<candies_size;++i)
            if (candies.at(i)+extraCandies>=m)
                ans.at(i)=true;
        return ans;
    }
};
