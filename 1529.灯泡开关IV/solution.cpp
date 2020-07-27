/*
* 每次变灯会影响[i,n-1]
* 那么从右到左变灯的话，变了一个灯，右边刚变好的灯会变化
* 从左到右变灯，不会影响到左边已经变好的灯
* 且一次变一堆灯，刚开始从全0状态开始，可以转换成滑窗的感觉来做
*/
class Solution {
public:
    int minFlips(string target) {
        int i=0;
        int size=target.size();
        int ans=0;
        for (i=0;i<size;++i)
            if (target.at(i)=='1')
                break;
        for (;i<size;++i)
            if (i==0 || target.at(i)!=target.at(i-1))
                ++ans;
        return ans;
    }
};
