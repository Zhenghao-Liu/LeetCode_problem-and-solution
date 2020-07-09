//a-> <-b碰撞后会变成<-a b->那么可以直接换名字看成<-b a->即直接穿过去
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=INT_MIN;
        for (int i:right)
            ans=max(ans,n-i);
        for (int i:left)
            ans=max(ans,i);
        return ans;
    }
};
