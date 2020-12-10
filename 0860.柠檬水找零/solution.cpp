class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cash5=0;
        int cash10=0;
        int cash20=0;
        for (int i:bills)
        {
            if (i==5)
                ++cash5;
            else if (i==10)
            {
                if (cash5==0)
                    return false;
                --cash5;
                ++cash10;
            }
            else if (i==20)
            {
                if (cash10!=0 && cash5!=0)
                {
                    --cash5;
                    --cash10;
                    ++cash20;
                }
                else if (cash5>=3)
                {
                    cash5-=3;
                    ++cash20;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
