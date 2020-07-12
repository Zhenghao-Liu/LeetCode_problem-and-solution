/*
* 有N台洗衣机衣服数量总和是D，即只有D是N的倍数才能均分衣服
* 若能均分衣服，则最后每台洗衣机的最终衣服是D/N件
* 那么用machines[i]都减去D/N，
  若对应第i台洗衣机数为正数，说明它需要拿出衣服给别的洗衣机
  若对应第i台洗衣机数为负数，说明需要从别的洗衣机得到衣服
* 每一次操作一台洗衣机最多可以拿出1件衣服，但是最多可以从左右各得到1件衣服或者只得到1件或不得到衣服
** 因此对于拿出衣服最多可能操作次数就是上述减去D/N后的最大值
** 而对于受到衣服，对于前i台洗衣机，他们的对应的数和为y，则需要和N-i太洗衣机至少传递|y|次衣服，且每次只能传递意见
** 最终结论：1.数组元素的最大值
            2.数组元素前缀和的绝对值的最大值
*/
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum=accumulate(machines.begin(),machines.end(),0);
        int machines_size=machines.size();
        if (sum%machines_size!=0)
            return -1;
        int target=sum/machines_size;
        for (int &i:machines)
            i-=target;
        int prefix=0;
        int ans=0;
        for (int &i:machines)
        {
            ans=max(ans,i);
            prefix+=i;
            ans=max(ans,abs(prefix));
        }
        return ans;
    }
};
