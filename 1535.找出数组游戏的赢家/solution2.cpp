/*
1. 首先题目说了一定有答案，那么显然arr数组中的最大值一定是可以满足k的，但不一定是从左到右第一个满足k的元素
2. 对于i、j，且i<j
   倘若[i]满足[i]大于范围[i+1 ··· j]的所有元素，但[i]又小于[j+1]，设k=j+1
   此时对于统计赢的次数就重新开始了即赢得次数为0，但是有没有必要把范围[i ··· j]再移到数组的末尾呢?
   我们先不移，因为移了就是和普通模拟没啥区别了
   自然比较到数组的末尾只有两种情况
3. 情况1：未到末尾已经赢的次数大于k了，所以就可以直接返回[k]了
4. 情况2：比较到末尾，但是赢得次数小于k，按模拟的话就是借着比较[i ··· j]，但是仔细想一想，前面已经验证过了[i ··· j]的元素是小于[k]的，且现在又验证得[k]是大于[k+1 ··· arr.size()-1]的，是不是就验证了[k]是arr中的最大值呢？那么根据结论1，自然[k]就是答案
5. 注意一种特殊情况，就是k=1的时候，这时候若[i]<[i+1]，表明[i+1]就已经赢了一次了，所以直接返回[i+1]
*/
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int arr_size=arr.size();
        if (k>=arr_size-1)
            return *max_element(arr.begin(),arr.end());
        int cur_winner=arr.at(0);
        int win_times=0;
        for (int i=1;i<arr_size;++i)
            if (arr.at(i)<cur_winner)
            {
                ++win_times;
                if (win_times==k)
                    return cur_winner;
            }
            //else if (arr.at(i)>cur_winner)
            else
            {
                win_times=1;
                cur_winner=arr.at(i);
                if (k==1)
                    return cur_winner;
            }
        return cur_winner;
    }
};
