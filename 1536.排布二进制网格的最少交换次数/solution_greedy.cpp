/*
* 既然只关心后面有几个0，可以先统计出来即count，然后直接操作count即可
* 对于i越小（图像中越高）的行，要求的0越多
  对于i越大（图像中越低）的行，要求的0越少
* 倘若对于a、b都能满足第i行的要求，那么a、b也必然能满足i+1行以及图像中更低行的要求
  所以贪心：从图像中高到低去遍历行，如果满足第i行的要求，则将该行进行交换到第i行，类似于选择排序，同理冒泡也可以做
*/
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int size=grid.size();
        //几个0
        vector<int> count(size);
        int index=0;
        for (vector<int> &i:grid)
        {
            int j;
            for (j=size-1;j>=0;--j)
                if (i.at(j)==1)
                    break;
            count.at(index)=size-j-1;
            ++index;
        }
        int ans=0;
        for (int target=size-1;target>=0;--target)
        {
            bool judge_find=false;
            int target_i;
            for (int i=size-target-1;i<size;++i)
                if (count.at(i)>=target)
                {
                    judge_find=true;
                    target_i=i;
                    break;
                }
            if (!judge_find)
                return -1;
            int ii=target_i;
            while (ii!=size-target-1)
            {
                ++ans;
                swap(count.at(ii),count.at(ii-1));
                --ii;
            }
        }
        return ans;
    }
};
