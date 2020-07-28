class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        return min((int)unordered_set<int>(candies.begin(),candies.end()).size(),(int)candies.size()/2);
    }
};
