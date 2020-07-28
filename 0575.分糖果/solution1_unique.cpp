/*
* 要想均分的情况下分给妹妹最多的糖果，
* 那就贪心的分，每个种类都挑一个给妹妹，
  直到每个种类妹妹都有了但是还没有均分完，则剩下的随便分
  或者是妹妹手中的糖果都是不同的种类，但不是candies中的所有种类，但是已经均分完了，不能再分了
* 综上即是min(糖果得种类，均分的数量=糖果的总数/2)
*/
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(),candies.end());
        int kinds=unique(candies.begin(),candies.end())-candies.begin();
        int size=candies.size();
        return min(kinds,size/2);
    }
};
