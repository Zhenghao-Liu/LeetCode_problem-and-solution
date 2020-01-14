//将从左到右乘积直接在answer上进行第一步操作，在计算从右到左乘积时用一个变量存乘积即可
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return {};
        vector<int> answer(nums_size);
        answer.at(0)=1;
        for (int i=1;i<nums_size;++i)
            answer.at(i)=answer.at(i-1)*nums.at(i-1);
        int right=nums.back();
        for (int i=nums_size-2;i>=0;--i)
        {
            answer.at(i)=answer.at(i)*right;
            right=right*nums.at(i);
        }
        return answer;
    }
};
