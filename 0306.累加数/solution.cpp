//先枚举找好前面两个数字的所有组合，后面一直匹配就可以
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int num_size=num.size();
        if (num_size<3)
            return false;
        bool answer=false;
        string left="",right;
        long long left_num=0,right_num;
        for (int i=0;i+1<=num_size-i-2;++i)
        {
            left+=num.at(i);
            if (left.size()!=1 && left.at(0)=='0')
                return false;
            left_num=left_num*10-'0'+num.at(i);
            right.clear();
            right_num=0;
            for (int j=i+1;max(i+1,j-i)<=num_size-j-1;++j)
            {
                right+=num.at(j);
                if (right.size()!=1 && right.at(0)=='0')
                    break;
                right_num=right_num*10-'0'+num.at(j);
                long long sum_num=left_num+right_num;
                string sum=to_string(sum_num);
                if (num.find(sum,j+1)==j+1)
                    answer=helper(num,right_num,sum_num,j+sum.size()+1);
                if (answer)
                    return true;
            }
        }
        return false;
    }
    bool helper(string &num,long long left_num,long long right_num,int index)
    {
        if (index==num.size())
            return true;
        long long sum_num=left_num+right_num;
        string sum=to_string(sum_num);
        if (num.find(sum,index)==index)
            return helper(num,right_num,sum_num,index+sum.size());
        return false;
    }
};
