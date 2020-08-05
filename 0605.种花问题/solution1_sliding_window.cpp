//滑窗方式去找有几个连续的0，但是要注意0在数组的开头或末尾两种特殊边界情况
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n==0)
            return true;
        int flowerbed_size=flowerbed.size();
        int cur=n;
        for (int i=0;i<flowerbed_size;++i)
        {
            if (flowerbed.at(i)==0)
            {
                int j;
                for (j=i+1;j<flowerbed_size;++j)
                    if (flowerbed.at(j)==1)
                        break;
                if (i==0)
                    i=i-1;
                if (j==flowerbed_size)
                    j=j+1;
                int can=(j-i-1)/2;
                cur-=can;
                if (cur<=0)
                    return true;
                i=j;
            }
        }
        return false;
    }
};
