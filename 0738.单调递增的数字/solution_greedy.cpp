//找到第一个不是递增的地方，然后找最右边可以减1的地方，后面全部补9
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string num=to_string(N);
        int num_size=num.size();
        string ans;
        ans+=num.at(0);
        int ans_length=1;
        for (int i=1;i<num_size;++i)
        {
            if (num.at(i)>=ans.at(ans_length-1))
            {
                ans+=num.at(i);
                ++ans_length;
            }
            else
            {
                int j=i-1;
                while (j>0 && ans.at(j)==ans.at(j-1))
                    --j;
                ans.at(j)=char(ans.at(j)-1);
                for (++j;j<ans_length;++j)
                    ans.at(j)='9';
                break;
            }
        }
        ans.append(num_size-ans_length,'9');
        return stoi(ans);
    }
};
