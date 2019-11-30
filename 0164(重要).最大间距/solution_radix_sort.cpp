//基数排序 时间复杂度O(nk)，n为个数，k为最大的数的位数(101有3位)
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int nums_size=nums.size(),max_nums=INT_MIN;
        if (nums_size<2)
            return 0;
        for (int &i:nums)
            if (i>max_nums)
                max_nums=i;
        vector<vector<int>> radix(10);
        int index=0;
        while (max_nums!=0)
        {
            for (int &i:nums)
                radix.at(i/int(pow(10,index))%10).push_back(i);
            nums.clear();
            for (vector<int>& vector_i:radix)
                for (int &i:vector_i)
                    nums.push_back(i);
            ++index;
            max_nums=max_nums/10;
            for (vector<int>& i:radix)
                i.clear();
        }
        int answer=INT_MIN;
        for (int i=1;i<nums_size;++i)
            if (nums.at(i)-nums.at(i-1)>answer)
                answer=nums.at(i)-nums.at(i-1);
        return answer;
    }
};
