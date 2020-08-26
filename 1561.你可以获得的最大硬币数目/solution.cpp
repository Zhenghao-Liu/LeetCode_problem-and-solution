//贪心：每次拿面值最大的两枚硬币，配一枚面值最小的硬币
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(),piles.rend());
        int ans=0;
        int size=(int)piles.size()/3;
        int index=1;
        for (int i=0;i<size;++i)
        {
            ans+=piles.at(index);
            index+=2;
        }   
        return ans;
    }
};
