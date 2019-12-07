class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return "0";
        for (int i=0;i<nums_size;++i)
            for (int j=i+1;j<nums_size;++j)
                if ((to_string(nums.at(i))+to_string(nums.at(j)))
                    <(to_string(nums.at(j))+to_string(nums.at(i))))
                    swap(nums.at(i),nums.at(j));
        string answer="";
        bool judge_zero=true;
        for (int &i:nums)
            if (i!=0)
            {
                judge_zero=false;
                break;
            }
        if (judge_zero)
            return "0";
        for (int &i:nums)
            answer.append(to_string(i));
        return answer;
    }
};
