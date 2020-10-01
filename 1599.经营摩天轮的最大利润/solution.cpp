//模拟，每一趟最大只能4个人
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& cus, int bc, int rc) {
        int people=0;
        int ans=0;
        int a=0,aa=0;
        for (int i=0;i<cus.size() || people>0;++i)
        {
            if (i<cus.size())
                people+=cus.at(i);
            int cur=min(people,4);
            people-=cur;
            ans+=cur*bc-rc;
            if (ans>aa)
            {
                a=i+1;
                aa=ans;
            }
        }
        return aa>0 ? a : -1;
    }
};
