/*
* 每次取出两个数字，实现加减乘除，再放回数组中，直到只剩一个数字为止
* 一共有加减乘除4种运算
  第一步：从4个数中有序选取2个，共有4*3种抽法
  第二步：从3个数中有序选取2个，共有3*2种抽法
  第三步：从2个数中有序选取2个，共有2*1种抽法
  所以对于4个数一共有4*3*4 * 3*2*4 * 2*1*4=9216种可能性
* 因为是实数除法，所以要用double，且注意精度问题，且注意除数为0的情况
* 且因为加法乘法是有交换律的，所以只用搜索一次即可，第二次可以剪枝
*/
const int ADD=0,MUL=1,SUB=2,DIV=3;
const double EPSILON=1e-6;
const int TARGET=24;
class Solution {
public:
    bool judgePoint24(vector<int>& _nums) {
        vector<double> nums;
        for (int i:_nums)
            nums.push_back(i);
        return dfs(nums);
    }
    bool dfs(vector<double> & nums)
    {
        if (nums.size()==1)
            return fabs(nums.at(0)-TARGET)<EPSILON;
        vector<double> next_nums;
        int nums_size=nums.size();
        for (int i=0;i<nums_size;++i)
            for (int j=0;j<nums_size;++j)
            {
                if (i==j)
                    continue;
                next_nums.clear();
                for (int k=0;k<nums_size;++k)
                    if (k!=i && k!=j)
                        next_nums.push_back(nums.at(k));
                for (int k=0;k<4;++k)
                {
                    if (k<2 && i>j)
                        continue;
                    switch(k)
                    {
                        case ADD:
                            next_nums.push_back(nums.at(i)+nums.at(j));
                            break;
                        case MUL:
                            next_nums.push_back(nums.at(i)*nums.at(j));
                            break;
                        case SUB:
                            next_nums.push_back(nums.at(i)-nums.at(j));
                            break;
                        case DIV:
                            if (fabs(nums.at(j)-0)<EPSILON)
                                continue;
                            next_nums.push_back(nums.at(i)/nums.at(j));
                            break;
                    }
                    if (dfs(next_nums))
                        return true;
                    next_nums.pop_back();
                }
            }
        return false;
    }
};
