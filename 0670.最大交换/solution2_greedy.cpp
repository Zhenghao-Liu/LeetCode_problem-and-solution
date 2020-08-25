/*
* 有交换意义即num从左向右遍历必须有一个递减的区间
* 以该位置为分界线
* 向右找最大的数，设为target
* 向左找小于target的位置在最左边的数，设为wanted
* 交换target和wanted即可
*/
class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int s_size=s.size();
        int i;
        for (i=1;i<s_size;++i)
            if (s.at(i)>s.at(i-1))
                break;
        if (i==s_size)
            return num;
        int target=i;
        int pos=i;
        for (++i;i<s_size;++i)
            if (s.at(i)>=s.at(target))
                target=i;
        int wanted;
        for (i=pos-1;i>=0;--i)
            if (s.at(i)<s.at(target))
                wanted=i;
        swap(s.at(wanted),s.at(target));
        return stoi(s);
    }
};
