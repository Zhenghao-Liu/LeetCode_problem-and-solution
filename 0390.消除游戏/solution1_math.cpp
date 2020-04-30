class Solution {
public:
    int lastRemaining(int n) {
        //count当前剩下的个数
        int count=n;
        //当前序列中从左到右的第一个数是first
        int first=1;
        //每一次删除元素后，新的从左到右第一个元素和旧的之间差值(也是未删除时候的公差)
        int diff=1;
        //分从左到右还是从右到左
        bool left_to_right=true;
        while (count>1)
        {
            //从左到右的话，第一个数必然删除，留下来的就是第二个数，直接加上公差即第二个数
            if (left_to_right)
                first+=diff;
            else
            {
                //从右到左的话要分两种情况
                //当前序列为奇数时，[1 2 3 4 5]删除后变成[2 4]第一数变成了第二个数
                if (count&1==1)
                    first+=diff;
                //当前序列为偶数时，[1 2 3 4]删除后变成[1 3]那么第一个数还是第一个数
            }
            count>>=1;
            diff<<=1;
            left_to_right=!left_to_right;
        }
        return first;
    }
};
