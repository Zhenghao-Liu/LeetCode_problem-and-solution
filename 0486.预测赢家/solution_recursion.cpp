/*
* 在先手选择了数 x 时，我们可以将当前的和增加 x
* 而在后手选择了数 y 时，我们可以将当前的和减去 y
* 这样先手胜利当且仅当最后的和大于等于 0
* 假设当前剩下的数为 nums[s .. e]，并且是先手的轮次
  那么先手可以选择 nums[s] 或者 nums[e]，并把当前的和对应增加 nums[s] 或者 nums[e]，并交给后手选数
  由于先手会选择最优的玩法，因此它会选择 nums[s] + winner(s + 1, e) 与 nums[e] + winner(s, e - 1) 中的较大值
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return winner(nums,0,nums.size()-1,1)>=0;
    }
    int winner(vector<int> &nums,int start,int end,int turn)
    {
        if (start==end)
            return turn*nums.at(start);
        int a=turn*nums.at(start)+winner(nums,start+1,end,-turn);
        int b=turn*nums.at(end)+winner(nums,start,end-1,-turn);
        return turn*max(turn*a,turn*b);
    }
};
