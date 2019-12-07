//降低了排序的复杂度
class Solution {
public:
    static bool cmp(const string &a,const string &b)
    {
        return (a+b)>(b+a);
    }
    string largestNumber(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return "0";
        bool judge_zero=true;
        vector<string>nums_s;
        for (int &i:nums)
        {
            if (i!=0 && judge_zero)
                judge_zero=false;
            nums_s.push_back(to_string(i));
        }
        if (judge_zero)
            return "0";
        sort(nums_s.begin(),nums_s.end(),cmp);
        string answer="";
        for (string &i:nums_s)
            answer.append(i);
        return answer;
    }
};
