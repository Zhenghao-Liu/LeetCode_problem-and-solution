/*
 * 最后只有两种情况：
   1. 所有项目都能完成
   2. 剩下一个项目有部分任务没有做完
 * 这两种情况是互斥的，所以讨论剩下有任务没完成的情况
 * 这种情况会出现一个项目特别大，大到比其他项目的所有任务总和都要大
   那么这时可以完成的任务总数就是：剩下其他所有任务的总和*2+1
   * 乘2解释为，先选其他项目任务，再选这个最大项目，这种方式
   * 加1解释为，最后其他项目任务都做完了，还可以做一次这个最大项目的一个任务
 * 剩下的情况则是所有项目所有任务都能完成
 */
typedef long long ll;
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        ll mx=*max_element(milestones.begin(),milestones.end());
        ll sum=accumulate(milestones.begin(),milestones.end(),ll(0));
        if (mx>sum-mx) {
            ll diff=sum-mx;
            return diff*2+1;
        }
        return sum;
    }
};