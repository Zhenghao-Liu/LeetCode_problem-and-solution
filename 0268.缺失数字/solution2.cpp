//异或法：因为缺失了一个数，我们可以把它转换成一个数出现了一次其余数都出现了两次的题目
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int nums_size=nums.size();
        int answer=0;
        for (int i=0;i<nums_size;++i)
            answer=answer^(i+1)^nums.at(i);
        return answer;
    }
};
