/*
* 设最大需要花费时间任务的时间是max_count
  那么至少需要(n+1)*(max_count-1)+1才能完成任务
* 但是有可能这个max_count有重复的，即多个任务都是最大值
  所以总花费时间为ans1=(n+1)*(max_count-1)+值为最大值的个数
* 但是有可能将单个最大值所分配的空闲时间填满后，还有任务没有完成，
  在原本一个周期时间即n+1的后面直接加上这些未完成的任务即可，
  这样即每个周期时间里面的任务能够大于n，且能够最终完成所有任务
  这样子总花费时间就是ans2=tasks.size()
* 所以最终答案就是max(ans1,ans2)
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26);
        for (char &i:tasks)
            ++count.at(i-'A');
        sort(count.rbegin(),count.rend());
        int max_count=1;
        for (int i=1;i<26 && count.at(i)==count.at(0);++i)
            ++max_count;
        int ans1=(n+1)*(count.at(0)-1)+max_count;
        int ans2=tasks.size();
        return max(ans1,ans2);
    }
};
