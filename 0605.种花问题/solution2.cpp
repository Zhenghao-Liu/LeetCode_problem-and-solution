//简单暴力的遇到3个连续的0，则代表可以种一棵花，并将种花位置修改为1，但是同样注意0出现在数组开头、末尾的边界情况
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size=flowerbed.size();
        for (int i=0;i<size;++i)
        {
            if (flowerbed.at(i)==0 && (i-1==-1 || flowerbed.at(i-1)==0) && (i+1==size || flowerbed.at(i+1)==0))
            {
                flowerbed.at(i)=1;
                --n;
            }
            if (n<=0)
                return true;
        }
        return n<=0;
    }
};
