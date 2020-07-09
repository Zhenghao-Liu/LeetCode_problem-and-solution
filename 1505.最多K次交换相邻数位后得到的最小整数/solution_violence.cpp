//贪心：既然可以交换K次，那就在能交换次数的范围内，找最小的数字把它交换到前面来
//正解：线段树or树状数组
class Solution {
public:
    string minInteger(string num, int k) {
        int num_size=num.size();
        //剪枝，最多操作((n-1)*n)/2就可以使一个数变为升序的
        if ((num_size-1)*num_size/2<=k)
        {
            sort(num.begin(),num.end());
            return num;
        }
        int last=-1;
        while (k!=0 && last+1!=num_size)
        {
            ++last;
            int min_index=last;
            for (int i=last+1;i<num_size && i-last<=k;++i)
                if (num.at(min_index)>num.at(i))
                    min_index=i;
            k-=min_index-last;
            for (int j=min_index;j>last;--j)
                swap(num.at(j),num.at(j-1));
        }
        return num;
    }
};
