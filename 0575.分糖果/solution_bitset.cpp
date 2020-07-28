//[-100,000, 100,000]共200001个数可能，若采取二进制的1来表示，那么即200001bit即6251个int
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        
        bitset<200001> helper;
        for (int i:candies)
            helper.set(i+100000,1);
        int size=candies.size();
        return min((int)helper.count(),size/2);
    }
};
